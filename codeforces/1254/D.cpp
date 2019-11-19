#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 150010;
const int MOD = 998244353;

int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

int mpow(int b, int e) {
  int ret = 1;
  while (e) {
    if (e % 2 == 1) ret = mul(ret, b), --e;
    b = mul(b, b); e /= 2;
  }
  return ret;
}

int inv(int x) {
  return mpow(x, MOD - 2);
}

struct Tournament {
  int offset;
  vector<int> tree;

  Tournament(int n) {
    for (offset = 1; offset <= n; offset *= 2);
    tree.resize(2 * offset);
  }

  void inc(int node, int lo, int hi, int from, int to, int val) {
    if (hi <= from || to <= lo) return;
    if (lo >= from && hi <= to) {
      tree[node] = add(tree[node], val);
      return;
    }
    inc(2 * node, lo, (lo + hi) / 2, from, to, val);
    inc(2 * node + 1, (lo + hi) / 2, hi, from, to, val);
  }

  int get(int node) {
    int ret = 0;
    node += offset;
    for (; node > 0; node /= 2) ret = add(ret, tree[node]);
    return ret;
  }
};

int n, q, t, invn;
int sz[MAXN], disc[MAXN], fin[MAXN], dad[MAXN], sumd[MAXN];

vector<int> v[MAXN];
vector<pair<int, int>> light[MAXN];

inline bool cmp_size(const int a, const int b) {
  return sz[a] > sz[b];
}

void dfs(int node) {
  sz[node] = 1;
  disc[node] = ++t;
  for (int nxt : v[node]) {
    if (nxt == dad[node]) continue;
    dad[nxt] = node;
    dfs(nxt);
    sz[node] += sz[nxt];
  }
  sort(v[node].begin(), v[node].end(), cmp_size);
  if (dad[node] != -1)
    v[node].erase(find(v[node].begin(), v[node].end(), dad[node]));
  fin[node] = t;
}

void find_light(int node) {
  for (int i = 0; i < (int) v[node].size(); ++i) {
    int nxt = v[node][i];
    light[nxt] = light[node];
    if (i != 0) light[nxt].emplace_back(node, nxt);
    find_light(nxt);
  }
}

void type1(int node, int d, Tournament &T) {
  if (dad[node] != -1) {
    int val = mul(mul(n - (n - sz[node]), invn), d);
    T.inc(1, 0, T.offset, 1, disc[node], val);
    T.inc(1, 0, T.offset, fin[node] + 1, t + 1, val);
  }
  if (v[node].size() > 0) {
    int big = v[node][0];
    int val = mul(mul(n - sz[big], invn), d);
    T.inc(1, 0, T.offset, disc[big], fin[big] + 1, val);
  }
  sumd[node] = add(sumd[node], d);
}

int type2(int node, Tournament &T) {
  int ret = add(sumd[node], T.get(disc[node]));
  for (auto &p : light[node]) {
    int val = mul(mul(n - sz[p.second], invn), sumd[p.first]);
    ret = add(ret, val);
  }
  return ret;
}

int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  dad[0] = -1;
  dfs(0);
  find_light(0);

  invn = inv(n);
  Tournament T(t + 10);

  for (int i = 0; i < q; ++i) {
    int qt;
    scanf("%d", &qt);
    if (qt == 1) {
      int node, d;
      scanf("%d%d", &node, &d); --node;
      type1(node, d, T);
    } else {
      int node;
      scanf("%d", &node); --node;
      printf("%d\n", type2(node, T));
    }
  }

  return 0;
}
