#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

int t, n;
int one[MAXN], zero[MAXN];

char s[MAXN];

void solve() {
  scanf("%s", s);
  n = strlen(s);

  one[0] = zero[0] = 0;
  for (int i = 0; i < n; ++i) {
    one[i + 1] = one[i] + (s[i] == '1');
    zero[i + 1] = zero[i] + (s[i] == '0');
  }

  int sol = n;
  for (int i = 0; i <= n; ++i) {
    sol = min(sol, one[i] + (zero[n] - zero[i]));
    sol = min(sol, zero[i] + (one[n] - one[i]));
  }

  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
