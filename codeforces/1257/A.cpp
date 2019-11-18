#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int t, n, x, a, b;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &x, &a, &b);
    printf("%d\n", min(n - 1, abs(a - b) + x));
  }
  return 0;
}
