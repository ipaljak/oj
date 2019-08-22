#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
const llint INF = 1e18 + 10;

int t, n;
char s[MAXN];

llint a, b;
llint memo[MAXN][2];

llint dp(int curr, bool up) {
  auto &ref = memo[curr][up];
  if (ref != -1) return ref;
  if (s[curr] == '1' && !up) return ref = INF;
  if (curr == n - 1) {
    if (!up)
      return ref = a + b;
    else
      return ref = 2LL * a + b;
  }
  llint ret = INF;
  if (!up) {
    if (s[curr] == '0') {
      ret = min(ret, b + a + dp(curr + 1, false));
      ret = min(ret, 2LL * a + 2LL * b + dp(curr + 1, true));
    } else {
      ret = min(ret, 2LL * a + 2LL * b + dp(curr + 1, true));
    }
  } else {
    if (s[curr] == '0') {
      ret = min(ret, a + 2LL * b + dp(curr + 1, true));
      ret = min(ret, 2LL * a + b + dp(curr + 1, false));
    } else {
      ret = min(ret, a + 2LL * b + dp(curr + 1, true));
    }
  }
  return ref = ret;
}

void solve() {
  scanf("%d", &n);
  scanf("%lld%lld", &a, &b);
  scanf("%s", s);
  for (int i = 0; i <= n + 1; ++i) memo[i][0] = memo[i][1] = -1;
  printf("%lld\n", b + dp(0, 0));
}

int main(void) {
  scanf("%d", &t);
  while (t --> 0) solve();
  return 0;
}
