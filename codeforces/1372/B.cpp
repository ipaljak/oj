#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, n;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int x = 1;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        x = n / i;
        break;
      }
    }
    printf("%d %d\n", x, n - x);
  }
  return 0;
}
