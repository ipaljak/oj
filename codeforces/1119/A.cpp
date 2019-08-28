#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int n;
int c[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &c[i]);

  int sol = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] != c[0]) sol = max(sol, i);
    if (c[i] != c[n - 1]) sol = max(sol, n - i - 1);
  }

  printf("%d\n", sol);
  return 0;
}
