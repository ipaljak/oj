#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    llint a, b, c, r;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &r);
    if (a > b) swap(a, b);
    llint l1 = c - r, l2 = c + r;
    llint L = max(l1, a), R = min(l2, b);
    //TRACE(L _ R);
    if (l1 > b || a > l2) {
      printf("%lld\n", b - a);
    } else {
      printf("%lld\n", (b - a + 1) - (R - L + 1));
    }
  }
  return 0;
}
