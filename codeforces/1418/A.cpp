#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, x, y, k;

inline llint ceil(llint a, llint b) {
  return (a + b - 1) / b;
}

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &x, &y, &k);
    llint p = ceil((llint) k * (y + 1) - 1LL, (llint) x - 1LL);
    printf("%lld\n", p + (llint) k);
  }
  return 0;
}
