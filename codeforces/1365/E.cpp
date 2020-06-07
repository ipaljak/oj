#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 505;

int n;
llint a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);

  llint sol = 0;
  for (int i = 0; i < n; ++i) {
    sol = max(sol, a[i]);
    for (int j = i + 1; j < n; ++j) {
      sol = max(sol, a[i] | a[j]);
      for (int k = j + 1; k < n; ++k)
        sol = max(sol, a[i] | a[j] | a[k]);
    }
  }

  printf("%lld\n", sol);
  return 0;
}
