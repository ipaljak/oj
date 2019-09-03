#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int n, k;
int sol[MAXN], c[MAXN];

set<pair<int, int>> s;

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

  llint cost = 0;
  int c_ptr = 0;

  for (int ti = k + 1; ti <= k + n; ++ti) {
    while (c_ptr < n && c_ptr + 1 <= ti) {
      s.insert({-c[c_ptr], c_ptr});
      ++c_ptr;
    };
    assert(s.size() > 0);
    auto p = *s.begin();
    sol[p.second] = ti;
    s.erase(s.begin());
  }

  for (int i = 0; i < n; ++i)
    cost += (llint) c[i] * (sol[i] - i - 1);

  printf("%lld\n", cost);
  for (int i = 0; i < n; ++i) printf("%d ", sol[i]);
  printf("\n");

  return 0;
}
