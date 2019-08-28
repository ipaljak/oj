#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int n;
llint a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);

  llint left = 0, sol = 0;
  for (int i = 0; i < n; ++i) {
    llint x = min(a[i] / 2, left);
    sol += x;
    left -= x;
    a[i] -= 2LL * x;
    sol += a[i] / 3;
    a[i] %= 3;
    left += a[i];
  }

  printf("%lld\n", sol);
  return 0;
}
