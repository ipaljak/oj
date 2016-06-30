#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN = 510;

bool dp[MAXN][MAXN][MAXN];

int N, K;
int c[MAXN];

int main(void) {

  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; ++i)
    scanf("%d", &c[i]);

  set<int> sol;

  dp[0][0][0] = true; 
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= K; ++j) {
      for (int k = 0; k <= K; ++k) {
        if (j >= c[i - 1]) dp[i][j][k] |= dp[i - 1][j - c[i - 1]][k];
        if (k >= c[i - 1]) dp[i][j][k] |= dp[i - 1][j][k - c[i - 1]]; 
        dp[i][j][k] |= dp[i - 1][j][k];
        if (dp[i][j][k] && j + k == K) {
            sol.insert(j);
            sol.insert(k);
        }
      }
    }
  }

  printf("%d\n", (int) sol.size());
  for (auto e : sol)
    printf("%d ", e);

  printf("\n");

  return 0;

}
