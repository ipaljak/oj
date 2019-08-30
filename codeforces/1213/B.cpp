#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 150010;

int t, n;
int a[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int sol = 0, mn = 1e7;
  for (int i = n - 1; i >= 0; --i) {
    sol += a[i] > mn;
    mn = min(mn, a[i]);
  }
  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
