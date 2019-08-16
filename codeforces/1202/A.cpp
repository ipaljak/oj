#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, na, nb;
char a[MAXN], b[MAXN];

void solve() {
  scanf("%s%s", a, b);
  na = strlen(a);
  nb = strlen(b);
  int fb = nb - 1, sol = 0;
  for (int i = 0; i < nb; ++i)
    if (b[i] == '1') fb = nb - i - 1;
  for (int i = na - fb - 1; i >= 0; --i) {
    if (a[i] == '1') break;
    ++sol;
  }
  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t --> 0) solve();
  return 0;
}
