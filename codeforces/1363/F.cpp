#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e3 + 10;

char a[MAXN], b[MAXN];

int t, n;
int dp[MAXN][MAXN], cnt_a[30][MAXN], cnt_b[30][MAXN];

inline void init() {
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      dp[i][j] = n + 1;

  for (int i = 0; i < 26; ++i)
    cnt_a[i][n] = cnt_b[i][n] = 0;

  cnt_a[a[n - 1] - 'a'][n - 1] = 1;
  cnt_b[b[n - 1] - 'a'][n - 1] = 1;

  for(int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) {
      cnt_a[j][i] = cnt_a[j][i + 1];
      cnt_b[j][i] = cnt_b[j][i + 1];
    }
    cnt_a[a[i] - 'a'][i]++;
    cnt_b[b[i] - 'a'][i]++;
  }
}

void solve() {
  scanf("%d", &n);
  scanf("%s%s", a, b);
  init();

  bool ok = true;
  for (int i = 0; i < 26; ++i)
    ok &= cnt_a[i][0] == cnt_b[i][0];

  if (!ok) {
    printf("-1\n");
    return;
  }

  for (int i = 0; i <= n; ++i)
    dp[0][i] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (a[i - 1] == b[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      if (cnt_a[b[j - 1] - 'a'][i] > cnt_b[b[j - 1] - 'a'][j])
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
    }
  }

  printf("%d\n", dp[n][n]);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
