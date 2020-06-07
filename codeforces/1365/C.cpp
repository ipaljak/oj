#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
int a[MAXN], b[MAXN], loc_a[MAXN], rot[MAXN], pts[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]); --a[i];
    loc_a[a[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]); --b[i];
    if (loc_a[b[i]] >= i)
      rot[b[i]] = loc_a[b[i]] - i;
    else
      rot[b[i]] = n - (i - loc_a[b[i]]);
    pts[rot[b[i]]]++;
  }

  int sol = 0;
  for (int i = 0; i < n; ++i)
    sol = max(sol, pts[i]);

  printf("%d\n", sol);

  return 0;
}
