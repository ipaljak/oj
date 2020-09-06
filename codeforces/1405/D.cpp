#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

vector<int> v[MAXN];

int t;
int n, a, b, da, db;
int d[MAXN];

inline void init() {
  for (int i = 0; i < n; ++i) {
    d[i] = -1;
    v[i].clear();
  }
}

void bfs(int node, int *dd) {
  queue<int> Q;
  Q.push(node);
  dd[node] = 0;
  while (!Q.empty()) {
    int node = Q.front(); Q.pop();
    for (int nxt : v[node]) {
      if (dd[nxt] != -1) continue;
      dd[nxt] = dd[node] + 1;
      Q.push(nxt);
    }
  }
}

void solve() {
  scanf("%d%d%d%d%d", &n, &a, &b, &da, &db); --a; --b;
  init();
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y); --x; --y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  bfs(a, d);
  if (db < 2 * da + 1 || d[b] <= da) {
    printf("Alice\n");
    return;
  }

  int piv = 0;
  for (int i = 0; i < n; ++i)
    if (d[piv] < d[i]) piv = i;

  for (int i = 0; i < n; ++i) d[i] = -1;
  bfs(piv, d);
  int diam = 0;
  for (int i = 0; i < n; ++i)
    diam = max(diam, d[i]);

  if (2 * da >= diam)
    printf("Alice\n");
  else
    printf("Bob\n");

}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
