#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 105;

int t, r, s;
int m[MAXN][MAXN];

void solve() {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < s; ++j)
      scanf("%d", &m[i][j]);

  llint sol = 0;
  for (int i = 0; i < (r + 1) / 2; ++i) {
    for (int j = 0; j < (s + 1) / 2; ++j) {
      vector<int> v;
      v.push_back(m[i][j]);
      if (j != s - j - 1) v.push_back(m[i][s - j - 1]);
      if (i != r - i - 1) v.push_back(m[r - i - 1][j]);
      if (j != s - j - 1 && i != r - i - 1) v.push_back(m[r - i - 1][s - j - 1]);
      sort(v.begin(), v.end());
      int m = v[v.size() / 2];
      for (int x : v) sol += (llint) abs(m - x);
    }
  }

  printf("%lld\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
