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
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2 || y1 == y2) {
      printf("%lld\n", (llint) abs(x1 - x2) + (llint) abs(y1 - y2));
    } else {
      printf("%lld\n", (llint) abs(x1 - x2) + (llint) abs(y1 - y2) + 2LL);
    }
  }
  return 0;
}
