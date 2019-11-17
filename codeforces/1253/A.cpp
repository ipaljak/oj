#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, n;
int a[MAXN], b[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  bool pref = true, suff = false;
  int diff = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i] && (pref || suff)) continue;
    if (a[i] == b[i]) { suff = true; continue; }
    if (suff) { printf("NO\n"); return; }
    if (pref) { diff = a[i] - b[i]; pref = false; continue; }
    if (diff != a[i] - b[i]) { printf("NO\n"); return; }
  }
  if (diff > 0)
    printf("NO\n");
  else
    printf("YES\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
