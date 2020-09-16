#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];

bool check(int x) {
  int l = x, r = n - 1;
  int lst = -1;
  while (l < r) {
    if (min(a[l], a[r]) < lst) return false;
    lst = min(a[l], a[r]);
    if (a[l] < a[r]) ++l; else --r;
  }
  return true;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) hi = mid; else lo = mid + 1;
  }
  printf("%d\n", lo);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
