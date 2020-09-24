#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int t, n, q, cookie;
int a[MAXN], bio[MAXN];

llint sol;

void update(int j, int c) {
  for (int i = max(1, j - 5); i <= min(n, j + 5); ++i) {
    if (bio[i] == cookie) continue;
    bio[i] = cookie;
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) sol += (llint) a[i] * c;
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) sol -= (llint) a[i] * c;
  }
}

void solve() {
  scanf("%d%d", &n, &q);
  a[0] = -1; a[n + 1] = -1;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  sol = 0, cookie = 1;
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] < a[i] && a[i] > a[i + 1]) sol += (llint) a[i];
    if (a[i - 1] > a[i] && a[i] < a[i + 1]) sol -= (llint) a[i];
  }

  printf("%lld\n", sol);
  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    ++cookie;
    update(l, -1); update(r, -1);
    swap(a[l], a[r]);
    ++cookie;
    update(l, 1); update(r, 1);
    printf("%lld\n", sol);
  }
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
