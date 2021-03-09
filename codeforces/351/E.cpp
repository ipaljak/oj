#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2010;

int n;
int a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < 0) a[i] *= -1;
  }

  llint sol = 0;
  for (int i = 0; i < n; ++i) {
    int l = 0, r = 0;
    for (int j = 0; j < n; ++j) {
      l += a[j] < a[i] && j < i;
      r += a[j] < a[i] && j > i;
    }
    sol += (llint)min(l, r);
  }

  printf("%lld\n", sol);
  return 0;
}
