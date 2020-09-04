#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MAXN = 205;

int n, k;
char s[MAXN], t[3];

int memo[MAXN][MAXN][MAXN];

int dp(int i, int j, int k) {
  if (memo[i][j][k] != -1) return memo[i][j][k];
  if (i == n) return memo[i][j][k] = 0;
  int ret = dp(i + 1, j, k);
  if (s[i] == t[0]) ret = max(ret, dp(i + 1, j + 1, k));
  if (s[i] == t[1]) ret = max(ret, j + dp(i + 1, j, k));
  if (k > 0) {
    ret = max(ret, dp(i + 1, j + 1, k - 1));
    ret = max(ret, j + dp(i + 1, j, k - 1));
  }
  return memo[i][j][k] = ret;
}

int main(void) {
  scanf("%d%d", &n, &k);
  scanf("%s%s", s, t);

  if (t[0] == t[1]) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += s[i] == t[0];
    cnt = min(n, cnt + k);
    printf("%d\n", cnt * (cnt - 1) / 2);
    return 0;
  }

  memset(memo, -1, sizeof memo);
  printf("%d\n", dp(0, 0, k));
  return 0;
}
