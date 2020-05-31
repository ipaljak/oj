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
    int n, k, odd = 0, even = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      odd += x % 2;
      even += (x + 1) % 2;
    }
    bool ok = false;
    for (int i = 1; i <= n; i += 2) {
      if (i <= odd && i <= k && k - i <= even)
        ok = true;
    }
    if (ok) printf("Yes\n"); else printf("No\n");
  }
  return 0;
}
