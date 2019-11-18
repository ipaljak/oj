#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int t, x, y;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &x, &y);
    if (x == 1) {
      if (y == 1) printf("YES\n"); else printf("NO\n");
      continue;
    }
    if (x < 4) {
      if (y < 4) printf("YES\n"); else printf("NO\n");
      continue;
    }
    printf("YES\n");
  }
  return 0;
}
