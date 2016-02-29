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

int n; 

vector <pii> v; 

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        v.emplace_back(a, b); 
    }

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (v[j].second == v[i].first) {
                ++sol;
                break;
            }
        }
    }

    printf("%d\n", n - sol);

    return 0;

}

