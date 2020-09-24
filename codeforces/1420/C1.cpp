#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int t, n, q;
int a[MAXN];

llint memo[MAXN][3];

inline void init() {
  for (int i = 0; i < n + 2; ++i)
    memo[i][0] = memo[i][1] = -1;
}

llint dp(int i, bool pos) {
  if (memo[i][pos] != -1) return memo[i][pos];
  if (i == n) return memo[i][pos] = 0LL;
  llint ret = dp(i + 1, pos);
  if (pos)
    ret = max(ret, dp(i + 1, !pos) + (llint) a[i]);
  else
    ret = max(ret, dp(i + 1, !pos) - (llint) a[i]);
  return memo[i][pos] = ret;
}

void solve() {
  scanf("%d%d", &n, &q); init();
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  printf("%lld\n", dp(0, true));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
