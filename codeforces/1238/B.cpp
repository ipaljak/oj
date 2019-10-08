#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int q, n, r;

int main(void) {
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &n, &r);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int sol = 0;
    for (int i = x.size() - 1; i >= 0; --i) {
      if (x[i] - sol * r > 0) ++sol;
    }
    printf("%d\n", sol);
  }
  return 0;
}
