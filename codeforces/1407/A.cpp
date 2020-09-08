#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;

int t;
int n;
int a[MAXN];

void solve() {
  scanf("%d", &n);
  int zero = 0, one = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    zero += a[i] == 0;
    one += a[i] == 1;
  }

  if (zero >= one) {
    printf("%d\n", zero);
    for (int i = 0; i < zero; ++i) printf("0 ");
    printf("\n");
    return;
  }

  if (one % 2 == 1) --one;
  printf("%d\n", one);
  for (int i = 0; i < one; ++i) printf("1 ");
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
