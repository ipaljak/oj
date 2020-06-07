#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 510;

int t, n;
int a[MAXN], b[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
    printf("No\n");
    return;
  }

  multiset<pair<int, int>> A, B;
  for (int i = 0; i < n / 2; ++i)
    A.insert({min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])});
  for (int i = 0; i < n / 2; ++i)
    B.insert({min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1])});

  if (A == B) printf("Yes\n"); else printf("No\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
