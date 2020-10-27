#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 210;
const int INF = 1e8;

int t, n;
int a[MAXN], memo[2 * MAXN][MAXN][MAXN];

inline void init() {
  for (int i = 0; i < 2 * n + 5; ++i)
    for (int j = 0; j < n + 5; ++j)
      for (int k = 0; k < n + 5; ++k)
        memo[i][j][k] = -1;
}

int dp(int i, int l, int r) {
  if (memo[i][l][r] != -1) return memo[i][l][r];
  if (l > r) return memo[i][l][r] = 0;
  if (i > 2 * n) return memo[i][l][r] = INF;
  int ret = dp(i + 1, l, r);
  ret = min(ret, abs(i - a[l]) + dp(i + 1, l + 1, r));
  ret = min(ret, abs(i - a[r]) + dp(i + 1, l, r - 1));
  return memo[i][l][r] = ret;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  init();

  printf("%d\n", dp(1, 0, n - 1));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
