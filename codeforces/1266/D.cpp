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
  Edge() {}
  Edge(int _a, int _b, llint _c) : a(_a), b(_b), c(_c) {}
};

int n, m;

llint debt[MAXN];
priority_queue<pair<llint, int>> pos, neg;

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    debt[a] += c;
    debt[b] -= c;
  }

  llint psum = 0, nsum = 0;
  for (int i = 0; i < n; ++i) {
    if (debt[i] < 0) {
      neg.push({-debt[i], i});
      nsum += -debt[i];
    }
    if (debt[i] > 0) {
      pos.push({debt[i], i});
      psum += debt[i];
    }
  }

  assert(psum == nsum);

  vector<Edge> sol;
  while (!pos.empty()) {
    auto p = pos.top();
    pos.pop();
    while (p.first > 0) {
      auto q = neg.top(); neg.pop();
      llint w = min(p.first, q.first);
      p.first -= w;
      q.first -= w;
      sol.emplace_back(p.second, q.second, w);
      if (q.first != 0) neg.push(q);
    }
  }

  printf("%d\n", (int) sol.size());
  for (auto &e : sol)
    printf("%d %d %lld\n", e.a + 1, e.b + 1, e.c);

  return 0;
}
