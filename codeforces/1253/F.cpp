#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;
const int MAXM = 3e5 + 10;

struct Edge {
  int a, b;
  llint c;
  Edge () {}
  Edge(int _a, int _b, llint _c) : a(_a), b(_b), c(_c) {}
  friend bool operator<(const Edge &A, const Edge &B) { return A.c < B.c; }
};

int n, m, k, q;
int a[MAXM], b[MAXM], c[MAXM], dad[MAXN];

llint dist[MAXN], sol[MAXM];

vector<pair<int, int>> v[MAXN];
priority_queue<pair<llint, int>, vector<pair<llint, int>>,
               greater<pair<llint, int>>> pq;

vector<Edge> E;
set<int> qset[MAXN];

int find(int x) {
  if (x == dad[x]) return x;
  return dad[x] = find(dad[x]);
}

void unite(int a, int b, llint c) {
  int pa = find(a), pb = find(b);
  if (pa == pb) return;
  if (qset[pa].size() > qset[pb].size()) swap(pa, pb);
  dad[pa] = pb;
  for (int x : qset[pa]) {
    if (qset[pb].find(x) != qset[pb].end())
      sol[x] = c;
    qset[pb].insert(x);
  }
}

void dijkstra() {
  memset(dist, -1, sizeof dist);
  for (int i = 0; i < k; ++i) pq.push({0, i});
  while (!pq.empty()) {
    while (!pq.empty() && dist[pq.top().second] != -1) pq.pop();
    if (pq.empty()) break;
    auto p = pq.top(); pq.pop();
    dist[p.second] = p.first;
    for (auto &q : v[p.second]) {
      int nxt = q.first, w = q.second;
      if (dist[nxt] != -1) continue;
      pq.push({p.first + w, nxt});
    }
  }
}

int main(void) {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]); --a[i]; --b[i];
    v[b[i]].emplace_back(a[i], c[i]);
    v[a[i]].emplace_back(b[i], c[i]);
  }

  dijkstra();

  for (int i = 0; i < m; ++i)
    E.emplace_back(a[i], b[i], (llint) c[i] + dist[a[i]] + dist[b[i]]);

  sort(E.begin(), E.end());
  for (int i = 0; i < n; ++i) dad[i] = i;

  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    qset[a].insert(i);
    qset[b].insert(i);
  }

  for (auto &e : E) unite(e.a, e.b, e.c);
  for (int i = 0; i < q; ++i) printf("%lld\n", sol[i]);

  return 0;
}
