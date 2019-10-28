#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
const int MAXK = 1e6 + 10;

int t;
int n, k, d;
int a[MAXN], cnt[MAXK];

void solve() {
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]); --a[i];
  }

  int curr = 0, sol = k;
  for (int i = 0; i < d; ++i) {
    if (cnt[a[i]] == 0) ++curr;
    ++cnt[a[i]];
  }

  sol = min(sol, curr);
  for (int i = d; i < n; ++i) {
    if (cnt[a[i - d]] == 1) --curr;
    --cnt[a[i - d]];
    if (cnt[a[i]] == 0) ++curr;
    ++cnt[a[i]];
    sol = min(sol, curr);
  }

  for (int i = n - d; i < n; ++i)
    --cnt[a[i]];

  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
