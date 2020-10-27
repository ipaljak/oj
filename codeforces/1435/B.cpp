#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 505;

int t, n, m;
int a[MAXN][MAXN], b[MAXN][MAXN];

void solve() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &b[i][j]);

  vector<int> p;
  for (int i = 0; i < m; ++i) {
    bool ok = false;
    for (int j = 0; j < n; ++j) {
      ok |= b[i][j] == a[0][0];
    }
    if (!ok) continue;

    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (b[i][j] == a[k][0]) p.push_back(k);
      }
    }
  }

  assert(p.size() == n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      printf("%d ", a[p[i]][j]);
    printf("\n");
  }
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
