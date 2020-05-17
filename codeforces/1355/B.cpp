#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    sort(a, a + n);
    int sol = 0, sz = 0;
    for (int i = 0; i < n; ++i) {
      ++sz;
      if (sz == a[i]) {
        sz = 0;
        ++sol;
      }
    }
    printf("%d\n", sol);
  }
  return 0;
}
