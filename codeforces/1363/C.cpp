#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

int t, n, x;
int sz[MAXN];

vector<int> v[MAXN];

void dfs(int node, int dad) {
  sz[node] = 1;
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    dfs(nxt, node);
    sz[node] += sz[nxt];
  }
}

inline void init() {
  for (int i = 0; i < n; ++i) {
    v[i].clear();
    sz[i] = 0;
  }
}

void solve() {
  scanf("%d%d", &n, &x); --x;
  init();
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dfs(x, -1);

  if (v[x].size() <= 1) {
    printf("Ayush\n");
    return;
  }

  int tot = 0;
  for (int xx : v[x])
    tot += sz[xx];

  //TRACE(tot);
  if (tot % 2 == 0) {
    printf("Ashish\n");
  } else {
    printf("Ayush\n");
  }
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
