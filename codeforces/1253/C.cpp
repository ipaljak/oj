#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n, m;
int a[MAXN];

llint pref[MAXN];

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  sort(a, a + n);
  for (int i = 1; i <= n; ++i) {
    pref[i] = (llint) a[i - 1];
    if (i - m >= 0) pref[i] += pref[i - m];
  }

  llint curr = 0;
  for (int i = 0; i < n; ++i) {
    curr += pref[i + 1];
    printf("%lld ", curr);
  }
  printf("\n");

  return 0;
}
