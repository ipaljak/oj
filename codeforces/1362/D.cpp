#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 10;

bool bio[MAXN];

int n, m;
int sol[MAXN], vv[MAXN];

vector<pair<int, int>> p;
vector<int> v[MAXN];

bool check(int node, int val) {
  set<int> s;
  for (int nxt : v[node]) {
    if (!bio[nxt]) continue;
    if (vv[nxt] == val) return false;
    if (vv[nxt] < val) s.insert(vv[nxt]);
  }
  return (int) s.size() == val - 1;
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) {
    int pi;
    scanf("%d", &pi);
    vv[i] = pi;
    p.emplace_back(pi, i);
  }

  sort(p.begin(), p.end());

  int cnt = 0;
  for (const auto &pp : p) {
    int node = pp.second;
    int val = pp.first;
    sol[cnt++] = node + 1;
    if (!check(node, val)) {
      printf("-1\n");
      return 0;
    }
    bio[node] = true;
  }

  for (int i = 0; i < n; ++i)
    printf("%d ", sol[i]);
  printf("\n");
  return 0;
}
