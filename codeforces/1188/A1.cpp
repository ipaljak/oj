#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int deg[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    ++deg[a]; ++deg[b];
  }

  for (int i = 0; i < n; ++i) {
    if (deg[i] == 2) { printf("NO\n"); return 0; }
  }

  printf("YES\n");
  return 0;
}
