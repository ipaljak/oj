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
    int a, b; scanf("%d%d", &a, &b);
    int x = abs(a - b);
    int sol = 0;
    for (int i : {5, 2, 1}) {
      sol += x / i;
      x -= (x / i) * i;
    }
    printf("%d\n", sol);
  }
  return 0;
}
