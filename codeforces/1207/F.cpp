#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 10;
const int KOR = 707;

int q;
int aa[MAXN];

llint a[710][710];

int main(void) {
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      aa[x] += y;
      for (int j = 1; j <= KOR; ++j)
        a[j][x % j] += (llint) y;
    } else {
      if (x <= KOR) {
        printf("%lld\n", a[x][y]);
      } else {
        llint ret = 0;
        for (int j = y; j <= 500000; j += x)
          ret += (llint) aa[j];
        printf("%lld\n", ret);
      }
    }
  }
  return 0;
}
