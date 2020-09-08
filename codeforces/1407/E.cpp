#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 10;

bool bio[MAXN];

int n, m;
int dad[MAXN], col[MAXN], dist[MAXN];

vector<pair<int, int>> v[MAXN];
vector<pair<int, int>> vv[MAXN];

int bfs() {
  memset(dist, -1, sizeof dist);
  queue<int> Q;
  Q.push(0);
  dist[0] = 0;
  while (!Q.empty()) {
    int node = Q.front(); Q.pop();
    for (auto &p : vv[node]) {
      if (p.second != col[node]) continue;
      if (dist[p.first] != -1) continue;
      dist[p.first] = dist[node] + 1;
      Q.push(p.first);
    }
  }
  return dist[n - 1];
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    if (a == b) continue;
    v[b].emplace_back(a, c);
    vv[a].emplace_back(b, c);
  }

  if (n == 1) {
    printf("0\n0\n");
    return 0;
  }

  memset(col, -1, sizeof col);
  set<int> s;
  s.insert(n - 1);

  int sol = 0;
  col[n - 1] = 0;
  bio[n - 1] = true;
  while (!s.empty()) {
    set<int> nxt;
    for (int x : s) {
      //TRACE(x);
      for (auto &p : v[x]) {
        //TRACE(p.first _ p.second _ bio[p.first] _ col[p.first]);
        if (bio[p.first]) continue;
        if (col[p.first] == -1) {
          col[p.first] = 1 - p.second;
          continue;
        }
        if (col[p.first] == p.second)
          nxt.insert(p.first);
      }
    }
    s = nxt;
    for (int x : nxt)
      bio[x] = true;
  }

  for (int i = 0; i < n; ++i)
    if (col[i] == -1) col[i] = 1;

  sol = bfs();

  printf("%d\n", sol);
  for (int i = 0; i < n; ++i)
    printf("%d", col[i]);
  printf("\n");
  return 0;
}
