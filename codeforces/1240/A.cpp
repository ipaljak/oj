#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int q, n, x, a, y, b;
int p[MAXN];

llint k, ab;

bool check(int cnt) {
  llint total = 0;
  int pos = 0;
  if (ab <= (llint) cnt) {
    int i = (int) ab;
    while (pos < cnt && i <= cnt) {
      total += (llint) (p[pos] / 100) * (x + y);
      i += (int) ab;
      ++pos;
    }
  }
  int i = a;
  while (pos < cnt && i <= cnt) {
    if (i % b != 0) {
      total += (llint) (p[pos] / 100) * x;
      ++pos;
    }
    i += a;
  }
  i = b;
  while (pos < cnt && i <= cnt) {
    if (i % a != 0) {
      total += (llint) (p[pos] / 100) * y;
      ++pos;
    }
    i += b;
  }
  //if (cnt == 6) TRACE(total);
  //if (cnt == 6) TRACE(total);
  return total >= k;
}

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
  sort(p, p + n); reverse(p, p + n);

  scanf("%d%d", &x, &a);
  scanf("%d%d", &y, &b);
  scanf("%lld", &k);

  ab = (llint) a * b / __gcd(a, b);
  if (x < y) {
    swap(x, y);
    swap(a, b);
  }

  //TRACE(ab);
  //check(6);
  //return;

  int lo = 0, hi = n + 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) hi = mid; else lo = mid + 1;
  }

  if (lo > n) {
    printf("-1\n");
  } else {
    printf("%d\n", lo);
  }
}

int main(void) {
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}
