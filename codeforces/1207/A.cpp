#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, b, p, f, h, c;

void solve() {
  scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
  int ret = 0;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j <= 100; ++j) {
      if (i <= p && j <= f && 2 * (i + j) <= b)
        ret = max(ret, h * i + c * j);
    }
  }
  printf("%d\n", ret);
}

int main(void) {
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) solve();
  return 0;
}
