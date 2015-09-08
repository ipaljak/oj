#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

#define MAXN 501

using namespace std;

typedef long long llint;

char grid[MAXN][MAXN];

int r, s, curr = 1, prev;

int dr1[] = {-1, 0, -1, 0};
int ds1[] = {0, -1, 0, -1};
int dr2[] = {-1, 0, 0, -1};
int ds2[] = {0, -1, -1, 0};

llint mod = 1000000007;
llint dp[2][MAXN][MAXN]; // n, r1, r2

inline bool check(int _r, int _s) {
    return _r >= 0 && _r < r && _s >= 0 && _s < s; 
}

llint ways(int r1, int s1, int r2, int s2, int i) {
    
    r1 += dr1[i]; s1 += ds1[i];
    r2 += dr2[i]; s2 += ds2[i];
   
    if (!check(r1, s1) || !check(r - r2 - 1, s - s2 - 1) ||  grid[r1][s1] != grid[r - r2 - 1][s - s2 - 1]) 
        return 0;

    return dp[prev][r1][r2];
    
}

inline bool connected(int r1, int s1, int r2, int s2) {
    if ((r + s - 1) % 2 != 0) 
        return r1 == r2 && s1 == s2; 
    else
        return r1 + 1 == r2 && s1 == s1 || r1 == r2 && s1 + 1 == s2;
}

int main(void) {
    
    scanf("%d%d", &r, &s);
    
    for (int i = 0; i < r; ++i) 
        scanf("%s", grid[i]);

    if (grid[0][0] != grid[r - 1][s - 1]) {
        printf("0\n");
        return 0;
    }

    int n = (r + s - 1) / 2 + (r + s - 1) % 2;

    dp[prev][0][0] = 1;
    llint sol = 0LL;
    
    for (int i = 1; i < n; ++i) {
        
        for (int r1 = 0; r1 <= i; ++r1) {
            for (int r2 = 0; r2 <= i; ++r2) {
                
                int s1 = i - r1, s2 = i - r2;
               
                dp[curr][r1][r2] = 0LL;
                if (!check(r1, s1) || !check(r - r2 - 1, s - s2 - 1) || grid[r1][s1] != grid[r - r2 - 1][s - s2 - 1])  
                    continue;
                
                for (int j = 0; j < 4; ++j) {
                    dp[curr][r1][r2] += ways(r1, s1, r2, s2, j);
                    dp[curr][r1][r2] %= mod;
                }

                if (i == n - 1 && connected(r1, s1, r - r2 - 1, s - s2 - 1)) {
                    sol += dp[curr][r1][r2];
                    sol %= mod;
                }

            }
        }
//
//        printf("Korak %d:\n", i);
//        for (int r1 = 0; r1 < r; ++r1) {
//            for (int r2 = 0; r2 < r; ++r2)
//                printf("%d ", (int) dp[curr][r1][r2]);
//            printf("\n");
//        }

        swap(prev, curr);
    }

    printf("%d\n", (int) sol);

    return 0;

}
