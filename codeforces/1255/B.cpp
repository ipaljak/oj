#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1010;

int t, n, m;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    llint sol = 0;
    for (int i = 0; i < n; ++i) {
      int x; scanf("%d", &x);
      sol += (llint) 2 * x;
    }
    if (m < n || n == 2) {
      printf("-1\n");
      continue;
    }
    printf("%lld\n", sol);
    for (int i = 0; i < n; ++i)
      printf("%d %d\n", i + 1, ((i + 1) % n) + 1);
  }
  return 0;
}
