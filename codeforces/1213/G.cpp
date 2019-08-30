#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n, q;
int pivot[MAXN], _size[MAXN];

llint sol[MAXN];

vector<pair<int, int>> edge[MAXN];
vector<pair<int, int>> vq;

void init() {
  for (int i = 0; i < n; ++i) {
    pivot[i] = i;
    _size[i] = 1;
  }
}

int find_set(int x) {
  if (pivot[x] == x) return x;
  return find_set(pivot[x]);
}

llint merge(int a, int b) {
  llint ret = 0;
  int pa = find_set(a), pb = find_set(b);
  assert(pa != pb);
  if (_size[pa] < _size[pb]) swap(pa, pb);
  ret = (llint) _size[pa] * _size[pb];
  pivot[pb] = pa;
  _size[pa] += _size[pb];
  return ret;
}

int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b;
    edge[c].emplace_back(a, b);
  }

  init();

  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    vq.emplace_back(x, i);
  }

  sort(vq.begin(), vq.end());
  int last = 0;
  llint ret = 0;
  for (const auto &p : vq) {
    while (last <= p.first) {
      for (const auto &q : edge[last])
        ret += merge(q.first, q.second);
      ++last;
    }
    sol[p.second] = ret;
  }

  for (int i = 0; i < q; ++i) printf("%lld ", sol[i]);
  printf("\n");

  return 0;
}
