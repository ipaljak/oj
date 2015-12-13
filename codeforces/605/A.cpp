#include <algorithm>
#include <cstdio>

#define MAXN 100010

using namespace std;

int n;
int dp[MAXN], sol;

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        sol = max(sol, dp[a] = 1 + dp[a - 1]);
    }    

    printf("%d\n", n - sol);
    
    return 0;

}

