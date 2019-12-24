#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int t, n, p, k;
int a[MAXN], pk[MAXN];

void solve() {
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (i - k < 0)
      pk[i] = 0;
    else
      pk[i] = a[i] + pk[i - k];
  }

  int sum = 0, x = 0;
  for (int i = k - 1; i < n; i += k) {
    if (sum + a[i] <= p) {
      ++x;
      sum += a[i];
    }
  }

  int sol = x * k;
  //TRACE(sol);
  sum = 0;
  for (int i = 0; i < k - 1; ++i) {
    if (x * k + i < n && sum + a[i] + pk[x * k + i] <= p) {
      ++sol;
    }
    sum += a[i];
  }

  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
