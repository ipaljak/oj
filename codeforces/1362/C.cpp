#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

llint calc(llint n) {
  if (n == 0) return 0;
  return calc(n / 2) + n;
}

int main(void) {
  scanf("%d", &t);
  while (t--) {
    llint n;
    scanf("%lld", &n);
    printf("%lld\n", calc(n));
  }
  return 0;
}
