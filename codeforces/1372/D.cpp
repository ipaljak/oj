#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
llint x[MAXN];

vector<llint> a;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &x[i]);

  for (int i = 0; i < n; i += 2)
    a.push_back(x[i]);

  for (int i = 1; i < n; i += 2)
    a.push_back(x[i]);

  for (int i = 0; i < n; ++i)
    a.push_back(a[i]);

  llint sum = 0, sol = 0;
  for (int i = 0; i < (n + 1) / 2; ++i)
    sum += a[i];

  sol = sum;
  for (int i = (n + 1) / 2; i < 2 * n; ++i) {
    sum += a[i];
    sum -= a[i - (n + 1) / 2];
    sol = max(sol, sum);
  }

  printf("%lld\n", sol);
  return 0;
}
