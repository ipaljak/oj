#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int q, n;

vector<int> v[MAXN];

inline void init() {
  for (int i = 0; i < n; ++i) v[i].clear();
}

pair<int, int> dfs(int node, int dad) {
  int chain = v[node].size() - 1, path = v[node].size() - 1;
  vector<int> ch;
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    auto p = dfs(nxt, node);
    path = max(path, p.second);
    chain = max(chain, (int) v[node].size() - 1 + p.first);
    ch.push_back(p.first);
  }
  path = max(path, chain);
  sort(ch.begin(), ch.end());
  if (ch.size() > 1)
    path =
        max(path, ch[ch.size() - 1] + ch[ch.size() - 2] + (int) v[node].size() - 1);
  return {chain, path};
}

void solve() {
  scanf("%d", &n);
  init();
  for (int i = 0; i < n - 1; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  printf("%d\n", dfs(0, 0).second + 2);
}

int main(void) {
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}
