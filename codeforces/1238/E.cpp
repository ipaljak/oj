#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

char s[MAXN];

int n, m;
int cnt[21][21], memo[1 << 20];

int dp(int mask) {
  if (memo[mask] != -1) return memo[mask];
  if (__builtin_popcount(mask) == m) return memo[mask] = 0;
  int ret = MOD;
  for (int i = 0; i < m; ++i) {
    if (mask & (1 << i)) continue;
    int cost = 0, pos = __builtin_popcount(mask);
    for (int j = 0; j < m; ++j) {
      if (j == i) continue;
      if (mask & (1 << j))
        cost += cnt[i][j] * pos;
      else
        cost -= cnt[i][j] * pos;
    }
    ret = min(ret, cost + dp(mask | (1 << i)));
  }
  return memo[mask] = ret;
}

int main(void) {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (int i = 1; i < n; ++i) {
    int a = s[i - 1] - 'a', b = s[i] - 'a';
    cnt[a][b]++;
    cnt[b][a]++;
  }

  memset(memo, -1, sizeof memo);
  printf("%d\n", dp(0));
  return 0;
}
