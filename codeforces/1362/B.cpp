#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, n;
int a[1 << 10];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sort(a, a + n);
  for (int k = 1; k < 1 << 10; ++k) {
    vector<int> v;
    for (int i = 0; i < n; ++i) v.push_back(a[i] ^ k);
    sort(v.begin(), v.end());
    bool ok = true;
    for (int i = 0; i < n; ++i)
      if (a[i] != v[i]) { ok = false; break; }
    if (ok) {
      printf("%d\n", k);
      return;
    }
  }

  printf("-1\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
