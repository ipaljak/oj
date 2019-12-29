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
    int n, k1, k2;
    scanf("%d%d%d", &n, &k1, &k2);
    bool win = false;
    for (int i = 0; i < k1; ++i) {
      int x;
      scanf("%d", &x);
      win |= x == n;
    }
    for (int i = 0; i < k2; ++i) {
      int x;
      scanf("%d", &x);
    }
    if (win) printf("YES\n"); else printf("NO\n");
  }
  return 0;
}
