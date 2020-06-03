#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int ceil(int x, int y) {
  return (x + y - 1) / y;
}

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int r, s;
    scanf("%d%d", &r, &s);
    printf("%d\n", ceil(r * s, 2));
  }
  return 0;
}
