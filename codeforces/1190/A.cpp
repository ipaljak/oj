#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXM = 1e5 + 10;

llint n, k;
llint p[MAXM];

int m;

int main(void) {
  scanf("%lld%d%lld", &n, &m, &k);
  for (int i = 0; i < m; ++i) { scanf("%lld", &p[i]); --p[i]; }

  int sol = 0, curr = 0;
  llint dp = 0;

  while (curr < m) {
    int cnt = 1;
    while (curr + 1 < m &&
           (p[curr] - dp) / k == (p[curr + 1] - dp) / k) {
      ++curr; ++cnt;
    }
    ++sol;
    dp += (llint) cnt;
    ++curr;
  }

  printf("%d\n", sol);
  return 0;
}
