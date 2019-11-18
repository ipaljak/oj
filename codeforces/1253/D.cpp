#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

bool bio[MAXN];

int n, m;
vector<int> v[MAXN];

pair<int, int> dfs(int node) {
  bio[node] = true;
  pair<int, int> ret = {node, node};
  for (int nxt : v[node]) {
    if (bio[nxt]) continue;
    auto p = dfs(nxt);
    ret.first = min(ret.first, p.first);
    ret.second = max(ret.second, p.second);
  }
  return ret;
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    v.emplace_back(dfs(i));
  }

  sort(v.begin(), v.end());

  auto curr = v[0];
  int sol = 0;
  for (int i = 1; i < (int) v.size(); ++i) {
    if (v[i].first > curr.second) {
      curr = v[i];
      continue;
    }
    ++sol;
    curr.second = max(curr.second, v[i].second);
  }

  printf("%d\n", sol);
  return 0;
}
