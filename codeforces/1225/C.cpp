#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

llint n, p;

int main(void) {
  scanf("%lld%lld", &n, &p);
  for (int k = 1; k < 32; ++k) {
    llint nn = n - k * p;
    if (nn < k || __builtin_popcount(nn) > k) continue;
    printf("%d\n", k);
    return 0;
  }
  printf("-1\n");
  return 0;
}
