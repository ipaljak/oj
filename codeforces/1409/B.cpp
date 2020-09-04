#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int a, b, x, y, n;
    scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);

    if (a - min(n, a - x) < b - min(n, b - y)) {
      int p = min(n, a - x);
      a -= p; n -= p;
      b -= min(n, b - y);
    } else {
      int p = min(n, b - y);
      b -= p; n -= p;
      a -= min(n, a - x);
    }
    printf("%lld\n", (llint) a * b);
  }
  return 0;
}
