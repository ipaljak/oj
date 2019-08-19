#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 101;

int n, m;
int a[MAXN], b[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  sort(a, a + n);
  sort(b, b + m);

  printf("%d %d\n", a[n - 1], b[m - 1]);
  return 0;
}
