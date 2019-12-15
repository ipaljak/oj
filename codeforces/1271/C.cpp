#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int n, sx, sy, A, B, C, D;
int x[MAXN], y[MAXN];

int main(void) {
  scanf("%d%d%d", &n, &sx, &sy);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    x[i] -= sx;
    y[i] -= sy;
    A += x[i] < 0;
    B += x[i] > 0;
    C += y[i] < 0;
    D += y[i] > 0;
  }

  if (A >= B && A >= C && A >= D) {
    printf("%d\n%d %d\n", A, sx - 1, sy);
    return 0;
  }

  if (B >= A && B >= C && B >= D) {
    printf("%d\n%d %d\n", B, sx + 1, sy);
    return 0;
  }

  if (C >= A && C >= B && C >= D) {
    printf("%d\n%d %d\n", C, sx, sy - 1);
    return 0;
  }

  if (D >= A && D >= B && D >= C) {
    printf("%d\n%d %d\n", D, sx, sy + 1);
    return 0;
  }

  assert(false);
  return 0;
}
