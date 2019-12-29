#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;

int t, n;
llint a[MAXN];

void solve() {
  scanf("%d", &n);
  llint sum = 0, xs = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    xs ^= a[i];
  }
  printf("2\n");
  printf("%lld %lld\n", xs, (sum + xs));
  llint A = sum + xs + sum + xs;
  llint B = xs ^ xs ^ (sum + xs);
  assert(A == 2 * B);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
