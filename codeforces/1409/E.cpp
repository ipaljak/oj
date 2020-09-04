#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n, k;
int x[MAXN], y[MAXN], l[MAXN], mx[MAXN];

void solve() {
  scanf("%d%d", &n, &k);
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
    v.emplace_back(x[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &y[i]);
  }

  sort(v.begin(), v.end());
  int lo = 0, hi = 0;
  for (; lo < n; ++lo) {
    while (hi < n && v[hi] <= v[lo] + k) ++hi;
    l[lo] = hi - lo;
  }

  mx[n - 1] = l[n - 1]; mx[n] = 0;
  for (int i = n - 2; i >= 0; --i)
    mx[i] = max(l[i], mx[i + 1]);

  int sol = 0;
  for (int i = 0; i < n; ++i) {
    assert(i + l[i] <= n);
    sol = max(sol, l[i] + mx[i + l[i]]);
  }

  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
