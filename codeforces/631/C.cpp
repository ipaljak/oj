#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>

#define MAXN 200010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n, q;
int a[MAXN], sol[MAXN]; 

vector <tuple<int, int, int> > v;
deque<int> dq;

int main(void) {

    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sol[i] = a[i];
    }

    int ptr = 0;
    for (int i = 0; i < q; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        v.emplace_back(-b, a, i); 
    }

    int curr = -1; 
    sort(v.begin(), v.end()); 
 
    vector<tuple<int, int, int> > tmp; 
    for (int i = 0; i < (int) v.size(); ++i) {
        if (get<2>(v[i]) > curr) {
            tmp.push_back(v[i]);
            curr = get<2>(v[i]);
        }
    }

    v = tmp; 
    curr = -1;

    sort(a, a - get<0>(v[0]));
    for (int i = 0; i < -get<0>(v[0]); ++i)
        dq.push_back(a[i]);

    for (int i = 0; i < v.size(); ++i) {
      
        int size, type, time;
        tie(size, type, time) = v[i]; size *= -1;  

//        printf("%d %d %d\n", size, type, time);

        int add = size;
        if (i != v.size() - 1) 
            add += get<0>(v[i + 1]);
    
        for (int j = 0; j < add; ++j) {
            if (type == 1) {
                a[size - j - 1] = dq.back();
                dq.pop_back();
            } else {
                a[size - j - 1] = dq.front();
                dq.pop_front(); 
            }
        }

    }

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    printf("\n");

    return 0;

}

