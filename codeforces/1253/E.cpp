#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 85;
const int MAXM = 1e5 + 10;

int n, m;
int x[MAXN], s[MAXN], memo[MAXM];

int dp(int i) {
  if (i > m) return 0;
  if (memo[i] != -1) return memo[i];
  int ret = 1 + dp(i + 1);
  for (int j = 0; j < n; ++j) {
    if (x[j] - s[j] <= i && x[j] + s[j] >= i) {
      ret = min(ret, dp(x[j] + s[j] + 1));
      continue;
    }
    if (x[j] < i) continue;
    ret = min(ret, x[j] - s[j] - i + dp(x[j] + s[j] + 1 + (x[j] - s[j] - i)));
  }
  return memo[i] = ret;
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &x[i], &s[i]);

  memset(memo, -1, sizeof memo);
  printf("%d\n", dp(1));
  return 0;
}
