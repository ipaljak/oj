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

struct Node {
  llint val, prop;
  Node () { prop = 0; val = INF;}
  Node (llint _val) {
    val = _val;
    prop = 0;
  }
};

class Tournament {
  public:
    int n, offset, from, to;
    vector<Node> tree;

    void propagate(int i) {
      if (i >= offset) return;
      for (int j = 2 * i; j <= 2 * i + 1; ++j) {
        tree[j].val += tree[i].prop;
        tree[j].prop += tree[i].prop;
      }
      tree[i].prop = 0;
    }

    void merge(int i) {
      if (i >= offset) return;
      tree[i].val = min(tree[2 * i].val, tree[2 * i + 1].val);
    }

    void add(int i, int lo, int hi, llint val) {
      if (from >= hi || to <= lo) return;
      if (lo >= from && hi <= to) {
        tree[i].prop += val;
        tree[i].val += val;
        return;
      }
      propagate(i);
      add(2 * i, lo, (lo + hi) / 2, val);
      add(2 * i + 1, (lo + hi) / 2, hi, val);
      merge(i);
    }

    void set(int i, int lo, int hi, llint val) {
      if (from >= hi || to <= lo) return;
      if (lo >= from && hi <= to) {
        tree[i].val = val;
        tree[i].prop = 0;
        return;
      }
      propagate(i);
      set(2 * i, lo, (lo + hi) / 2, val);
      set(2 * i + 1, (lo + hi) / 2, hi, val);
      merge(i);
    }

    int get_min(int i, int lo, int hi) {
      if (lo + 1 == hi) {
        assert(tree[i].val == 0);
        return lo;
      }
      propagate(i);
      if (tree[2*i + 1].val <= tree[2*i].val)
        return get_min(2 * i + 1, (lo + hi) / 2, hi);
      else
        return get_min(2 * i, lo, (lo + hi) / 2);
    }

    Tournament() {}
    Tournament(int _n) {
      n = _n;
      for (offset = 1; offset <= n; offset *= 2);
      tree.resize(2 * offset);
    }

    void add(int lo, int hi, llint val) {
      from = lo; to = hi;
      add(1, 0, offset, val);
    }

    void set(int lo, int hi, llint val) {
      from = lo; to = hi;
      set(1, 0, offset, val);
    }

    int get_min() {
      return get_min(1, 0, offset);
    }
};

int n;
int p[MAXN];
llint s[MAXN];

int main(void) {
  scanf("%d", &n);
  Tournament T(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &s[i]);
    T.set(i, i + 1, s[i]);
  }

  for (int i = 0; i < n; ++i) {
    int x = T.get_min();
    p[x] = i + 1;
    T.add(x + 1, n, -(i + 1));
    T.set(x, x + 1, INF);
  }

  for (int i = 0; i < n; ++i)
    printf("%d ", p[i]);
  printf("\n");

  return 0;
}
