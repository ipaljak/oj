#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int a, b;

int main(void) {
  scanf("%d%d", &a, &b);
  if (a == b) {
    printf("%d0 %d1\n", a, b);
    return 0;
  }

  if (a + 1 == b) {
    printf("%d %d\n", a, b);
    return 0;
  }

  if (a == 9 && b == 1) {
    printf("9 10\n");
    return 0;
  }

  printf("-1\n");
  return 0;
}
