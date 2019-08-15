#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
const llint INF = 1e18 + 10;

char buff[200];

int n, q;

struct Node {
  llint val, prop;
  Node() { val = INF; prop = 0; }
};

struct Tournament {
  int offset;
  vector<Node> tree;

  Tournament() {}
  Tournament(int size) {
    for (offset = 1; offset <= size; offset *= 2);
    tree.resize(2 * offset);
  }

  void propagate(int node) {
    if (node >= offset) return;
    for (int i = 2 * node; i <= 2 * node + 1; ++i) {
      tree[i].prop += tree[node].prop;
      tree[i].val += tree[node].prop;
    }
    tree[node].prop = 0;
  }

  void merge(int node) {
    tree[node].val = min(tree[2 * node].val, tree[2 * node + 1].val);
  }

  void set(int i, int val) {
    i += offset; tree[i].val = (llint) val; i /= 2;
    while (i > 0) { merge(i); i /= 2; }
  }

  void add(int node, int from, int to, int lo, int hi, int val) {
    propagate(node);
    if (to <= lo || hi <= from) return;
    if (from >= lo && to <= hi) {
      tree[node].prop = (llint) val;
      tree[node].val += (llint) val;
      return;
    }
    add(2 * node, from, (from + to) / 2, lo, hi, val);
    add(2 * node + 1, (from + to) / 2, to, lo, hi, val);
    merge(node);
  }

  llint get_min(int node, int from, int to, int lo, int hi) {
    propagate(node);
    if (to <= lo || hi <= from) return INF;
    if (from >= lo && to <= hi) return tree[node].val;
    llint left = get_min(2 * node, from, (from + to) / 2, lo, hi);
    llint right = get_min(2 * node + 1, (from + to) / 2, to, lo, hi);
    merge(node);
    return min(left, right);
  }
};

void add(int lo, int hi, int val, Tournament &T) {
  if (lo <= hi) {
    T.add(1, 0, T.offset, lo, hi + 1, val);
  } else {
    T.add(1, 0, T.offset, lo, n, val);
    T.add(1, 0, T.offset, 0, hi + 1, val);
  }
}

llint get_min(int lo, int hi, Tournament &T) {
  if (lo <= hi) return T.get_min(1, 0, T.offset, lo, hi + 1);
  return min(T.get_min(1, 0, T.offset, lo, n),
             T.get_min(1, 0, T.offset, 0, hi + 1));
}

int main(void) {
  scanf("%d", &n);
  Tournament T(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    T.set(i, x);
  }

  //TRACE(get_min(1, 1, T));
  //TRACE(get_min(3, 3, T));
  //TRACE(get_min(0, n - 1, T));
  //return 0;

  scanf("%d\n", &q);
  for (int i = 0; i < q; ++i) {
    gets(buff);
    int a, b, c;
    if (sscanf(buff, "%d%d%d", &a, &b, &c) == 2) {
      printf("%lld\n", get_min(a, b, T));
    } else {
      add(a, b, c, T);
    }
  }

  return 0;
}
