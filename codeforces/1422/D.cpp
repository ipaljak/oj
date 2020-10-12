#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

const llint INF = 1e16;

struct Node {
  int id;
  int x, y;
  Node(int x, int y, int id): id(id), x(x), y(y) {}
};

int n, m, sx, sy, fx, fy;
int x[MAXN], y[MAXN];

llint ds[MAXN];
llint sol;

vector<pair<int, int>> v[MAXN];
vector<Node> nodes;

bool cmp_x(const Node &A, const Node &B) {
  return A.x < B.x;
}

bool cmp_y(const Node &A, const Node &B) {
  return A.y < B.y;
}

void dijkstra(int st, llint *d) {
  priority_queue<pair<llint, int>> Q;
  Q.push({0LL, st});
  while (!Q.empty()) {
    while (!Q.empty() && d[Q.top().second] != -1) Q.pop();
    if (Q.empty()) break;
    llint dd = Q.top().first;
    int node = Q.top().second;
    Q.pop();
    d[node] = -dd;
    for (auto &p : v[node]) {
      int nxt = p.first, dist = p.second;
      if (d[nxt] != -1) continue;
      Q.push({dd - (llint) dist, nxt});
    }
  }
}

int main(void) {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &x[0], &y[0], &x[m + 1], &y[m + 1]);
  sol = (llint) abs(x[0] - x[m + 1]) + abs(y[0] - y[m + 1]);

  nodes.emplace_back(x[0], y[0], 0);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i + 1], &y[i + 1]);
    nodes.emplace_back(x[i + 1], y[i + 1], i + 1);
  }

  sort(nodes.begin(), nodes.end(), cmp_x);
  for (int i = 0; i < nodes.size() - 1; ++i) {
    v[nodes[i].id].emplace_back(nodes[i + 1].id, nodes[i + 1].x - nodes[i].x);
    v[nodes[i + 1].id].emplace_back(nodes[i].id, nodes[i + 1].x - nodes[i].x);
  }

  sort(nodes.begin(), nodes.end(), cmp_y);
  for (int i = 0; i < nodes.size() - 1; ++i) {
    v[nodes[i].id].emplace_back(nodes[i + 1].id, nodes[i + 1].y - nodes[i].y);
    v[nodes[i + 1].id].emplace_back(nodes[i].id, nodes[i + 1].y - nodes[i].y);
  }

  memset(ds, -1, sizeof ds);
  dijkstra(0, ds);
  //for (int i = 1; i <= m; ++i) printf("%lld ", ds[i]);
  //printf("\n");

  for (int i = 1; i <= m; ++i)
    sol = min(sol, ds[i] + (llint) abs(x[m + 1] - x[i]) + abs(y[m + 1] - y[i]));

  printf("%lld\n", sol);
  return 0;
}
