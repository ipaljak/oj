#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, n;
int a[MAXN], cnt[35];

llint choose2(int x) {
  return (llint) x * (x - 1) / 2;
}

void solve() {
  memset(cnt, 0, sizeof cnt);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    int mx = 0;
    for (int j = 0; (1 << j) <= a[i]; ++j)
      if (a[i] & (1 << j)) mx = j;
    cnt[mx]++;
  }

  llint sol = 0;
  for (int i = 0; i < 32; ++i)
    sol += choose2(cnt[i]);

  printf("%lld\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
