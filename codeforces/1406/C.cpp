#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, n;
int sz[MAXN], p[MAXN], leaf[MAXN];

vector<int> v[MAXN];

inline void init() {
  for (int i = 0; i < n; ++i) {
    sz[i] = 0;
    p[i] = -1;
    leaf[i] = -1;
    v[i].clear();
  }
}

void dfs(int node, int dad) {
  sz[node] = 1;
  p[node] = dad;
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    dfs(nxt, node);
    sz[node] += sz[nxt];
    leaf[node] = leaf[nxt];
  }
  if (leaf[node] == -1) leaf[node] = node;
}

void solve() {
  scanf("%d", &n);
  init();
  pair<int, int> e;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
    e = {a + 1, b + 1};
  }

  dfs(0, -1);
  int x = -1;
  for (int i = 0; i < n; ++i)
    if (sz[i] == n - sz[i]) x = i;

  if (x == -1) {
    printf("%d %d\n", e.first, e.second);
    printf("%d %d\n", e.first, e.second);
    return;
  }

  assert(p[x] != -1);
  printf("%d %d\n", p[leaf[x]] + 1, leaf[x] + 1);
  printf("%d %d\n", p[x] + 1, leaf[x] + 1);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
