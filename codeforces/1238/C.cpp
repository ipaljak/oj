#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int q, h, n;
int p[MAXN];

int main(void) {
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &h, &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    int curr = 1;
    int sol = 0;
    for (int i = 1; i < n; ++i) {
      if (p[i] + 1 == p[i - 1]) { ++curr; continue; }
      sol += (curr % 2) == 0;
      curr = 0;
    }
    if (p[n - 1] != 1) sol += (curr % 2) == 0;
    printf("%d\n", sol);
  }
  return 0;
}
