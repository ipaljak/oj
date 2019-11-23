#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e6 + 10;

char s[MAXN];
int q, n;
llint k;

void solve() {
  scanf("%d%lld", &n, &k);
  scanf("%s", s);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (k <= 0) continue;
    if (s[i] == '1') { ++cnt; continue; }
    llint jump = min(k, (llint) cnt);
    swap(s[i], s[i - (int) jump]);
    k -= jump;
  }
  printf("%s\n", s);
}

int main(void) {
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}
