#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

int n, l, r;

int main(void) {
  scanf("%d%d%d", &n, &l, &r);
  llint mn = (llint) (n - l) + (1LL << l) - 1LL;
  llint mx = (1LL << r) - 1LL + (llint) (n - r) * (1LL << (r - 1));
  printf("%lld %lld\n", mn, mx);
  return 0;
}
