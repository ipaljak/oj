#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int q;

int main(void) {
  scanf("%d", &q);
  while (q--) {
    int a, b, n, S;
    scanf("%d%d%d%d", &a, &b, &n, &S);
    int x = min(a, S / n) * n;
    int y = min(b, (S - x));
    if (x + y == S) printf("YES\n"); else printf("NO\n");
  }
  return 0;
}
