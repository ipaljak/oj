#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

llint n;

int main(void) {
  scanf("%lld", &n);

  int d = -1;
  for (int i = 2; (llint) i * i <= n; ++i) {
    if (n % i != 0) continue;
    while (n % i == 0) n /= (llint) i;
    d = i; break;
  }

  if (d == -1) {
    printf("%lld\n", n);
    return 0;
  }

  if (n != 1)
    printf("1\n");
  else
    printf("%d\n", d);
  return 0;
}
