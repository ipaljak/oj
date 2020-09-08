#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;

int t, n;
int a[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  reverse(a, a + n);
  int g = a[0];
  for (int i = 1; i < n; ++i) {
    int piv = i, gg = -1;
    for (int j = i; j < n; ++j) {
      if (__gcd(g, a[j]) > gg) {
        piv = j;
        gg = __gcd(g, a[j]);
      }
    }
    swap(a[i], a[piv]);
    g = __gcd(g, a[i]);
  }

  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
