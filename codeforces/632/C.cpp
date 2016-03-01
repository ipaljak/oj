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

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

struct str {
    
    string s, key;

    str () {}
    str (string _s) {
        s = _s; 
        key = _s;
        while (key.length() != 51) 
            key.push_back('z' + 1);
    }
    
    friend bool operator < (const str &A, const str &B) {
        return (A.s + B.s) < (B.s + A.s);
    }
    
};

int n; 

vector <str> v; 

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s; 
        v.emplace_back(s);
    }

    sort(v.begin(), v.end());

    for (str st : v)
        cout << st.s;

    cout << endl;

    return 0;

}

