#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 131075;

int t, n;
int cnt[27][MAXN];
char s[MAXN];

inline void init() {
  for (int i = 0; i < 26; ++i) {
    cnt[i][0] = (s[0] - 'a') == i;
    for (int j = 1; j < n; ++j)
      cnt[i][j] = cnt[i][j - 1] + ((s[j] - 'a') == i);
  }
}

int sum(int l, int r, int c) {
  if (l == 0) return cnt[c][r - 1];
  return cnt[c][r - 1] - cnt[c][l - 1];
}

int solve(int l, int r, int c) {
  assert(c < 26);
  if (r == l + 1) return (s[l] - 'a') != c;
  int L = solve(l, (l + r) / 2, c + 1);
  int R = solve((l + r) / 2, r, c + 1);
  int sz = (r - l) / 2;
  return min(R + sz - sum(l, (l + r) / 2, c),
             L + sz - sum((l + r) / 2, r, c));
}

void solve() {
  scanf("%d", &n);
  scanf("%s", s);
  init();
  printf("%d\n", solve(0, n, 0));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
