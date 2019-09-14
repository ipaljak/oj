#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 4;
const int MAXM = 110;

int t;
int n, m;
int a[MAXN + 1][MAXM], memo[(1 << MAXN) + 10][MAXM];

void init() {
  memset(memo, -1, sizeof memo);
}

int dp(int mask, int col) {
  if (mask == (1 << n) - 1 || col == m)
    return memo[mask][col] = 0;
  if (memo[mask][col] != -1) return memo[mask][col];
  int ret = 0;
  for (int rot = 0; rot < 4; ++rot) {
    for (int j = 0; j < (1 << n); ++j) {
      if ((j & mask) != 0) continue;
      int add = 0;
      for (int k = 0; k < n; ++k) {
        if ((j & (1 << k)) == 0) continue;
        add += a[(rot + k) % n][col];
      }
      ret = max(ret, add + dp(mask | j, col + 1));
    }
  }
  return memo[mask][col] = ret;
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &a[i][j]);
  init();
  printf("%d\n", dp(0, 0));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
