#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    if (abs(a[i] - a[i - 1]) >= 2) {
      printf("YES\n");
      printf("%d %d\n", i, i + 1);
      return;
    }
  }
  printf("NO\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
