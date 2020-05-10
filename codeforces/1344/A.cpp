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
  while (t-- > 0) {
    scanf("%d", &n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      s.insert(((i + x) % n + n) % n);
    }
    if (s.size() == n)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
