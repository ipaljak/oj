#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int a, b, c, d, e, f;

int main(void) {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  llint sol = 0;
  for (int i = 0; i <= 100000; ++i) {
    llint curr = 0;
    if (i > a || i > d) break;
    curr += (llint) i * e;
    curr += (llint) min(b, min(c, d - i)) * f;
    sol = max(sol, curr);
  }
  printf("%lld\n", sol);
  return 0;
}
