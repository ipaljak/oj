#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int q, n;
int a[MAXN], lo[MAXN], hi[MAXN], dp[MAXN];

set<int> s;

inline void init() {
  for (int i = 0; i < n; ++i) lo[i] = hi[i] = dp[i] = -1;
  s.clear();
}

void solve() {
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]); --a[i];
    if (lo[a[i]] == -1) lo[a[i]] = i;
    hi[a[i]] = i;
    s.insert(a[i]);
  }
  int prev = -1;
  int sol = 1;
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (it == s.begin()) { dp[*it] = 1; prev = *it; continue; }
    dp[*it] = 1;
    if (lo[*it] > hi[prev]) dp[*it] = 1 + dp[prev];
    sol = max(sol, dp[*it]);
    prev = *it;
  }
  printf("%d\n", (int) s.size() - sol);
}

int main(void) {
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}
