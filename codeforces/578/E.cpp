#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXN 100001

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

char s[MAXN];

int n;

set <int> l, r;
vector <vector <int> > ll, rr, lr, rl;

void to_vectors(set <int> &s, vector <vector <int> > &v) {
    for (set <int> :: iterator it = s.begin(); it != s.end(); ++it) {
        vector <int> tmp; tmp.push_back(*it);
        v.push_back(tmp);
    }
}

void add_chain(vector <int> &chain) {
    if (s[chain[0]] == 'L' && s[chain[chain.size() - 1]] == 'L') ll.push_back(chain);
    if (s[chain[0]] == 'L' && s[chain[chain.size() - 1]] == 'R') lr.push_back(chain);
    if (s[chain[0]] == 'R' && s[chain[chain.size() - 1]] == 'L') rl.push_back(chain);
    if (s[chain[0]] == 'R' && s[chain[chain.size() - 1]] == 'R') rr.push_back(chain);
}

void find_chains() {

    while (!l.empty() || !r.empty()) {
      
        if (l.empty()) { 
            to_vectors(r, rr);
            break;
        }

        if (r.empty()) {
            to_vectors(l, ll);
            break;
        }
        
        vector <int> chain;

        set <int> :: iterator l_it = l.begin(), r_it = r.begin();
        bool left = *l_it < *r_it;

        while ((left && l_it != l.end()) || (!left && r_it != r.end())) {
            if (left) {
                chain.push_back(*l_it);
                r_it = r.lower_bound(*l_it);
                l.erase(l_it);
            } else {
                chain.push_back(*r_it);
                l_it = l.lower_bound(*r_it);
                r.erase(r_it);
            }
            left = !left;
        } 

        add_chain(chain);

    }

}

inline void print_chains(vector<vector <int> > &v) {
    for (int i = 0; i < (int) v.size(); ++i) {
        for (int j = 0; j < (int) v[i].size(); ++j) {
            printf("%d ", v[i][j] + 1);
        }
//        printf("\n");
    }
}

int main(void) {

    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; ++i) 
        if (s[i] == 'R') r.insert(i); else l.insert(i);

    find_chains();

    printf("%d\n", (int) ll.size() + (int) lr.size() + (int) rl.size() + (int) rr.size() - 1);
    
    if (!lr.empty() && !rl.empty()) {
   
        vector <int> a, b;
        
        for (int i = 0; i < (int) lr.size(); ++i) 
            for (int j = 0; j < (int) lr[i].size(); ++j) 
                a.push_back(lr[i][j]);        
    
        for (int i = 0; i < (int) rl.size(); ++i) 
            for (int j = 0; j < (int) rl[i].size(); ++j) 
                b.push_back(rl[i][j]);        

        if (a.back() > b.back()) {
            b.push_back(a.back()); 
            a.pop_back();
        } else {
            a.push_back(b.back());
            b.pop_back();
        }

        ll.push_back(a);
        rr.push_back(b);
   
        lr.clear(); rl.clear();

    }

    if (ll.size() >= rr.size()) {
        if (!lr.empty()) print_chains(lr);
        for (int i = 0; i < (int) ll.size(); ++i) {
            for (int j = 0; j < (int) ll[i].size(); ++j) printf("%d ", ll[i][j] + 1);
            if (i == 0 && !rl.empty()) print_chains(rl);
            if (i < rr.size())
                for (int j = 0; j < (int) rr[i].size(); ++j) printf("%d ", rr[i][j] + 1);
        }
        if (ll.empty() && !rl.empty()) print_chains(rl);
    } else {
        if (!rl.empty()) print_chains(rl);
        for (int i = 0; i < (int) rr.size(); ++i) {
            for (int j = 0; j < (int) rr[i].size(); ++j) printf("%d ", rr[i][j] + 1);
            if (i == 0 && !lr.empty()) print_chains(lr);
            if (i < ll.size())
                for (int j = 0; j < (int) ll[i].size(); ++j) printf("%d ", ll[i][j] + 1);
        }
        if (rr.empty() && !lr.empty()) print_chains(lr);
    }

    printf("\n");

    return 0;

}

