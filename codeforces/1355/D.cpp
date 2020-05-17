#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int n, s;

int main(void) {
  scanf("%d%d", &n, &s);
  if (s >= 2 * n) {
    printf("YES\n");
    for (int i = 0; i < n - 1; ++i) printf("2 ");
    printf("%d\n1\n", s - 2 * (n - 1));
  } else {
    printf("NO\n");
  }
  return 0;
}
