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

#define MAXN 5010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

char dig[MAXN];

const int mod = 1000000007;

int N;
int _next[MAXN][MAXN], dp[MAXN][MAXN], pref_sum[MAXN][MAXN];

int main(void) {

    scanf("%d", &N);
    scanf("%s", dig);

    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (dig[i] != dig[j]) 
                _next[i][j] = 0;
            else
                _next[i][j] = 1 + _next[i + 1][j + 1];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
           
            if (i == 0) { 
                dp[i][j] = 1;        
            } else if (dig[i] != '0') {

                dp[i][j] += (pref_sum[i][i - 1] - pref_sum[max(0, 2 * i - j)][i - 1] + mod) % mod;
                dp[i][j] %= mod;

                if (2 * i - j - 1 >= 0) {
                    int x = _next[2 * i - j - 1][i];
                    if (i + x <= j && dig[2 * i - j - 1 + x] < dig[i + x]) {
                        dp[i][j] += dp[2 * i - j - 1][i - 1];
                        dp[i][j] %= mod;
                    }
                }
            }
            
            pref_sum[i + 1][j] = (pref_sum[i][j] + dp[i][j]) % mod;
//            printf("%d %d --> %d\n", i, j, dp[i][j]);

        }
    }

    int sol = 0;
    for (int i = 0; i < N; ++i) {
        sol += dp[i][N - 1];
        sol %= mod;
    }

    printf("%d\n", sol);

    return 0;

}

