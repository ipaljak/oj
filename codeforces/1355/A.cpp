#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    llint a, k;
    scanf("%lld%lld", &a, &k); --k;
    while (k) {
      int mind = 9, maxd = 0;
      llint _a = a;
      while (a) {
        mind = min(mind, (int)(a % 10));
        maxd = max(maxd, (int)(a % 10));
        a /= 10;
      }
      a = _a + (llint) mind * maxd;
      if (mind == 0) break;
      --k;
    }
    printf("%lld\n", a);
  }
  return 0;
}
