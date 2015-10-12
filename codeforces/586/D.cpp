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

#define MAXN 105

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

bool dp[5][MAXN];

char grid[5][MAXN];

int t, n, k;

inline void init() {
    memset(dp, false, sizeof dp);
}

void solve() {

    init();
    scanf("%d%d", &n, &k);

    for (int i = 0; i < 3; ++i) {
         scanf("%s", grid[i]);
         dp[i][0] = grid[i][0] == 's';
         if (grid[i][0] == 's') grid[i][0] = '.';
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < 3; ++i) {
            
            if (3 * j < n && grid[i][3 * j] != '.') continue;
            
            if (3 * j - 2 < n && grid[i][3 * j - 2] != '.') continue;
            dp[i][j] = dp[i][j - 1];
            
            if (i - 1 >= 0 && !(3 * j - 2 < n && grid[i - 1][3 * j - 2] != '.')) 
                dp[i][j] |= dp[i - 1][j - 1];
            
            if (i + 1 < 3 && !(3 * j - 2 < n && grid[i + 1][3 * j - 2] != '.')) 
                dp[i][j] |= dp[i + 1][j - 1];
        }
    }

//    printf("\n");
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%d", dp[i][j]);
//        }
//        printf("\n");
//    }

    bool pass = dp[0][n - 1] | dp[1][n - 1] | dp[2][n - 1];

    if (pass)
        printf("YES\n");
    else
        printf("NO\n");

}

int main(void) {

    scanf("%d", &t);
    while (t--) solve();

    return 0;

}

