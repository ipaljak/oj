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
    llint x;
    scanf("%lld", &x);
    llint r = x % 14;
    if (r >= 1 && r <= 6 && x > 14)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
