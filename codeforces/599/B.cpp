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
int f[MAXN], b[MAXN], sol[MAXN], cnt[MAXN];

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++cnt[x];
        f[x] = i + 1;
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]); 
        if (cnt[b[i]] == 0) {
            printf("Impossible\n");
            return 0;
        }
        sol[i + 1] = f[b[i]];
    }

    bool check = true;
    for (int i = 0; i < m; ++i) 
        check &= cnt[b[i]] == 1;

    if (!check) {
        printf("Ambiguity\n");
        return 0;
    }

    printf("Possible\n");
    for (int i = 0; i < m; ++i) 
        printf("%d ", sol[i + 1]);    

    printf("\n");

    return 0;

}


