#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long llint;

using namespace std;

int n;
int c[1005], sum_c[1005];

const llint mod = 1000000007;
llint choose[1005][1005];
llint dp[1005][1005];

inline void init() {
    choose[0][0] = 1LL;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) choose[i][j] = 1LL; else choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
            choose[i][j] %= mod;
        }
    }
}

llint rek(int col, int pos) {

    llint ret = 0;
    
    if (dp[col][pos] != -1) return dp[col][pos];
    if (col == n && pos == sum_c[n]) return dp[col][pos] = 1LL;
    if (pos == sum_c[n]) return dp[col][pos] = 0;

    ret = rek(col, pos + 1);
    
    if (pos - sum_c[col - 1] - 1 >= c[col] - 1) 
        ret += choose[pos - sum_c[col - 1] - 1][c[col] - 1] * rek(col + 1, pos + 1);
    
    ret %= mod;

    return dp[col][pos] = ret;

}


int main(void) {

    init();
    memset(dp, -1, sizeof dp);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i + 1]);
        sum_c[i + 1] = sum_c[i] + c[i + 1];
    }

    printf("%I64d\n", rek(1, 1));
    
    return 0;
    
}
