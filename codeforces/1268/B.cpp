#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 3e5 + 10;

int n;
int a[MAXN];

llint sum;

int main(void) {
  scanf("%d", &n);

  llint b = 0, w = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    b += (llint) a[i] / 2;
    w += (llint) a[i] / 2;
    if (a[i] % 2) {
      b += i % 2;
      w += (i % 2) == 0;
    }
  }

  printf("%lld\n", min(b, w));
  return 0;
}
