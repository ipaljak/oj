#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int b, g, n;

int main(void) {
  scanf("%d%d%d", &b, &g, &n);
  int sol = 0;
  for (int B = 0; B <= n; ++B) {
    int G = n - B;
    if (B <= b && G <= g) ++sol;
  }

  printf("%d\n", sol);
  return 0;
}
