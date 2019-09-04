#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int n, d, e;

int main(void) {
  scanf("%d%d%d", &n, &d, &e);

  int sol = n;
  for (int A = 0; A <= n / e; A += 5) {
    int _n = n;
    _n -= A * e;
    _n -= (_n / d) * d;
    sol = min(sol, _n);
  }

  printf("%d\n", sol);
  return 0;
}
