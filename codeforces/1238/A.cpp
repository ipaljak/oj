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
    if (a - b >= 2)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
