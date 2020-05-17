#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 10;

int a, b, c, d;
int pref[MAX], two[MAX];

int sum(int lo, int hi) {
  if (lo == 0) return pref[hi];
  return pref[hi] - pref[lo - 1];
}

int main(void) {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = a; i <= b; ++i)
    pref[i] = 1;
  for (int i = 1; i < MAX; ++i) pref[i] += pref[i - 1];
  for (int i = 0; i < MAX; ++i) {
    two[i] = sum(max(0, i - c), max(0, i - b));
  }

  llint sol = 0;
  for (int i = c + 1; i <= MAX; ++i)
    sol += (llint) min(i - c, d - c + 1) * two[i];

  printf("%lld\n", sol);
  return 0;
}
