#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int t, n;
int sz[MAXN];

llint w[MAXN];

vector<pair<int, int>> v[MAXN];

void dfs(int node, int dad) {
  sz[node] = 1;
  for (auto &p: v[node]) {
    int nxt = p.first;
    int ww = p.second;
    if (nxt == dad) continue;
    dfs(nxt, node);
    sz[node] += sz[nxt];
    w[node] += (llint) ww;
    w[node] += w[nxt];
  }
}

void solve() {
  scanf("%d", &n);
  llint A = 0, B = 0;
  for (int i = 0; i < 2*n; ++i) {
    v[i].clear();
    sz[i] = 0;
    w[i] = 0;
  }

  for (int i = 0; i < 2*n - 1; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    A += (llint) c;
    v[a].emplace_back(b, c);
    v[b].emplace_back(a, c);
  }

  dfs(0, -1);
  //for (int i = 0; i < 2*n; ++i) TRACE(sz[i] _ w[i]);

  for (int i = 0; i < 2*n; ++i) {
    for (auto &p : v[i]) {
      int j = p.first;
      if (j < i) continue;
      int a = i, b = j;
      if (sz[a] < sz[b]) swap(a, b);
      if (sz[b] % 2 == 0) A -= (llint) p.second;
      llint x = (llint) min(sz[b], 2 * n - sz[b]);
      B += x *  (llint) p.second;
    }
  }

  printf("%lld %lld\n", A, B);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
