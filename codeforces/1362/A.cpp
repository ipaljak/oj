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
    llint a, b;
    scanf("%lld%lld", &a, &b);
    if (a > b) swap(a, b);
    if (b % a != 0) {
      printf("-1\n");
      continue;
    }
    llint d = b / a;
    if (__builtin_popcountll(d) != 1) {
      printf("-1\n");
      continue;
    }
    int sol = 0;
    while (d != 1LL && d % 8LL == 0) {
      d /= 8LL;
      ++sol;
    }
    sol += d > 1;
    printf("%d\n", sol);
  }
  return 0;
}
