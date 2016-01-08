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

#define MAXN 100010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n, m;
int longest[MAXN];

vector <int> v[MAXN];

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        longest[i] = 1;
        for (int j = 0; j < (int) v[i].size(); ++j) {
            if (v[i][j] > i) continue;
            longest[i] = max(longest[i], longest[v[i][j]] + 1); 
        }
    }

    llint sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, (llint) longest[i] * (llint) v[i].size());
    }

    printf("%lld\n", sol);

    return 0;

}

