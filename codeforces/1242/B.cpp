#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;

int n, m;
int dad[MAXN], sz[MAXN];

vector<int> v[MAXN];
set<int> comps;

inline void init() {
  for (int i = 0; i < n; ++i) {
    dad[i] = i;
    sz[i] = 1;
  }
}

int find(int a) {
  if (a == dad[a]) return a;
  return dad[a] = find(dad[a]);
}

void unite(int a, int b) {
  int pa = find(a), pb = find(b);
  if (pa == pb) return;
  if (sz[pa] > sz[pb]) swap(pa, pb);
  sz[pb] += sz[pa];
  dad[pa] = dad[pb];
}

int main(void) {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    if (a < b)
      v[b].push_back(a);
    else
      v[a].push_back(b);
  }

  for (int i = 0; i < n; ++i) {
    map<int, int> cnt;
    comps.insert(i);
    for (int j : v[i]) cnt[find(j)]++;
    for (auto it = comps.begin(); it != comps.end();) {
      if (*it == i) { ++it; continue; }
      if (*it != dad[*it]) {
        it = comps.erase(it);
        continue;
      }
      if (cnt[*it] < sz[*it]) unite(*it, i);
      ++it;
    }
  }

  int sol = 0;
  for (int i = 0; i < n; ++i) sol += dad[i] == i;
  printf("%d\n", sol - 1);
  return 0;
}
