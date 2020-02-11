#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int n;

llint _x1, _y1, _x2, _y2;

int main(void) {
  scanf("%lld%lld%lld%lld", &_x1, &_y1, &_x2, &_y2);
  scanf("%d", &n);

  int sol = 0;
  for (int i = 0; i < n; ++i) {
    llint a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    llint p = _x1 * a + _y1 * b + c;
    llint q = _x2 * a + _y2 * b + c;
    if (min(p, q) < 0 && max(p, q) > 0) ++sol;
  }

  printf("%d\n", sol);
  return 0;
}
