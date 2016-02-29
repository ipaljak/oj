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
int a[MAXN], last[MAXN];

llint pref_add[MAXN];

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);    

    for (int i = 0; i < m; ++i) {
        int t; scanf("%d", &t);
        
        if (t == 1) {
            int x, y; scanf("%d%d", &x, &y);
            a[x - 1] = y; 
            pref_add[i + 1] = pref_add[i];
            last[x - 1] = i;
            continue;
        }
        
        if (t == 2) {
            int x; scanf("%d", &x);
            pref_add[i + 1] = pref_add[i] + (llint) x;
            continue;
        }

        int x; scanf("%d", &x);
        pref_add[i + 1] = pref_add[i];
        printf("%lld\n", (llint) a[x - 1] + pref_add[i + 1] - pref_add[last[x - 1]]);

    }

    return 0;

}

