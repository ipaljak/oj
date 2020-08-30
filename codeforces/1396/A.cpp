#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;

int n;
int mul[MAXN];

llint a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

  if (n == 1) {
    printf("1 1\n0\n1 1\n0\n1 1\n%lld\n", -a[0]);
    return 0;
  }

  mul[0] = 0;
  for (int i = 1; i <= n - 1; ++i)
    mul[(llint) i * (n - 1) % n] = i;

  for (int i = 1; i <= n - 1; ++i) assert(mul[i] != 0);

  printf("1 1\n");
  printf("%lld\n", (llint) n - (a[0] % n));
  a[0] += (n - (a[0] % n));

  printf("2 %d\n", n);
  for (int i = 1; i < n; ++i) {
    if (a[i] >= 0) {
      int x = n - (a[i] % n);
      printf("%lld ", (llint) mul[x] * (n - 1));
      a[i] += (llint) mul[x] * (n - 1);
    } else {
      int x = n - (abs(a[i]) % n);
      printf("%lld ", (llint) -mul[x] * (n - 1));
      a[i] -= (llint) mul[x] * (n - 1);
    }
  }
  printf("\n");

  printf("1 %d\n", n);
  for (int i = 0; i < n; ++i) {
    assert(abs(a[i]) % n == 0);
    printf("%lld ", -a[i]);
  }
  printf("\n");

  return 0;
}
