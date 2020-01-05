#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 105;

int n, e, o;
int p[MAXN], memo[MAXN][MAXN][MAXN][2];

set<int> s;

int dp(int i, int ee, int oo, bool last) {
  auto &ref = memo[i][ee][oo][last];
  if (ref != -1) return ref;
  if (i == n) return ref = 0;
  if (p[i] != 0) return ref = ((p[i] % 2) != last) + dp(i + 1, ee, oo, p[i] % 2);
  int ret = MAXN;
  assert(ee > 0 || oo > 0);
  if (ee > 0) ret = min(ret, last + dp(i + 1, ee - 1, oo, false));
  if (oo > 0) ret = min(ret, !last + dp(i + 1, ee, oo - 1, true));
  return ref = ret;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    if (p[i] != 0)
      s.insert(p[i]);
  }

  for (int i = 1; i <= n; ++i) {
    if (s.find(i) == s.end()) {
      e += (i % 2) == 0;
      o += i % 2;
    }
  }

  //TRACE(e _ o);

  memset(memo, -1, sizeof memo);

  int sol = MAXN;
  if (p[0] != 0) {
    sol = min(sol, dp(1, e, o, p[0] % 2));
  } else {
    if (e > 0) sol = min(sol, dp(1, e - 1, o, false));
    if (o > 0) sol = min(sol, dp(1, e, o - 1, true));
  }


  printf("%d\n", sol);
  return 0;
}
