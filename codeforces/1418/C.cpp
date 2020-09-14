#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];
int memo[MAXN][2];

inline void init() {
  for (int i = 0; i <= n + 2; ++i)
    memo[i][0] = memo[i][1] = -1;
}

int dp(int i, bool me) {
  if (i >= n) return memo[i][me] = 0;
  if (memo[i][me] != -1) return memo[i][me];
  if (me) {
    return memo[i][me] = min(dp(i + 1, !me), dp(i + 2, !me));
  } else {
    return memo[i][me] = min(a[i] + dp(i + 1, !me), a[i] + a[i + 1] + dp(i + 2, !me));
  }
}

void solve() {
  scanf("%d", &n); init();
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  a[n] = a[n + 1] = a[n + 2] = 0;
  printf("%d\n", dp(0, false));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
