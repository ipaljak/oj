#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int t, n;
int lst[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) lst[i] = -1;
  int sol = n + 1;
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x); --x;
    if (lst[x] != -1) sol = min(sol, i - lst[x] + 1);
    lst[x] = i;
  }
  if (sol == n + 1) sol = -1;
  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
