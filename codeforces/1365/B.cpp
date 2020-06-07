#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, n;
int a[MAXN], b[MAXN];

void solve() {
  scanf("%d", &n);
  bool sorted = true;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (i > 0 && a[i] < a[i - 1]) sorted = false;
  }
  bool one = false, zero = false;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    one |= b[i] == 1;
    zero |= b[i] == 0;
  }

  if ((one && zero) || sorted)
    printf("Yes\n");
  else
    printf("No\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
