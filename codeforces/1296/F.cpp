#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 10;

struct Path {
  int st, fin, cost;
  Path(int st, int fin, int cost) : st(st), fin(fin), cost(cost) {}
  friend bool operator<(const Path &A, const Path &B) {
    return A.cost > B.cost;
  }
};

int n, m;
int sol[MAXN];
int aa[MAXN], bb[MAXN], _prev[MAXN];

vector<int> v[MAXN];
vector<Path> path;
map<pair<int, int>, int> edge;

vector<int> get_path(int st, int fn) {
  memset(_prev, -1, sizeof _prev);
  queue<int> Q;
  Q.push(st);
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    for (int nxt : v[node]) {
      if (nxt == st || _prev[nxt] != -1) continue;
      _prev[nxt] = node;
      Q.push(nxt);
    }
  }

  vector<int> ret;
  while (fn != -1) {
    ret.push_back(fn);
    fn = _prev[fn];
  }

  return move(ret);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    if (a > b) swap(a, b);
    v[a].push_back(b);
    v[b].push_back(a);
    aa[i] = a; bb[i] = b;
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    path.emplace_back(a, b, c);
  }

  sort(path.begin(), path.end());
  for (const auto &p : path) {
    auto nodes = get_path(p.st, p.fin);
    bool ok = false;
    for (int i = 1; i < (int) nodes.size(); ++i) {
      int a = nodes[i - 1], b = nodes[i];
      if (a > b) swap(a, b);
      auto it = edge.find({a, b});
      if (it == edge.end() || it->second == p.cost) ok = true;
      if (it == edge.end())
        edge[{a, b}] = p.cost;
    }
    if (!ok) {
      printf("-1\n");
      return 0;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    auto it = edge.find({aa[i], bb[i]});
    if (it != edge.end())
      printf("%d ", it->second);
    else
      printf("%d ", path[0].cost);
  }
  printf("\n");

  return 0;
}
