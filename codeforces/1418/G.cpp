#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int INF = 1e9 + 7;
const int MAXN = 5e5 + 10;

int n;
int a[MAXN], cnt[MAXN];

vector<int> v[MAXN]; pair<int, int> prev_c[MAXN], prev_d[MAXN]; 
struct Tournament {
  struct Node {
    int mx, freq, prop;
    Node() : mx(-INF), freq(1), prop(0) {}
    Node(int mx, int freq, int prop) : mx(mx), freq(freq), prop(prop) {}
  };

  int off;
  vector<Node> tree;

  Tournament(int n) {
    for (off = 1; off <= n; off *= 2);
    tree.resize(2 * off);
  }

  void merge(int node) {
    if (node >= off) return;
    tree[node].mx = max(tree[2 * node].mx, tree[2 * node + 1].mx);
    tree[node].freq = 0;
    for (int i = 2 * node; i <= 2 * node + 1; ++i)
      if (tree[i].mx == tree[node].mx)
        tree[node].freq += tree[i].freq;
  }


  void propagate(int node) {
    if (node >= off) return;
    for (int i = 2 * node; i <= 2 * node + 1; ++i) {
      tree[i].mx += tree[node].prop;
      tree[i].prop += tree[node].prop;
    }
    tree[node].prop = 0;
  }

  void inc(int node, int from, int to, int lo, int hi, int val) {
    propagate(node);
    if (to <= lo || hi <= from) return;
    if (from >= lo && to <= hi) {
      tree[node].mx += val;
      tree[node].prop += val;
      propagate(node);
      return;
    }
    inc(2 * node, from, (from + to) / 2, lo, hi, val);
    inc(2 * node + 1, (from + to) / 2, to, lo, hi, val);
    merge(node);
  }

  void inc(int lo, int hi, int val) {
    //TRACE(lo _ hi _ val);
    inc(1, 0, off, lo, hi, val);
  }

  pair<int, int> get() {
    return {tree[1].mx, tree[1].freq};
  }
};

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    prev_c[a[i]] = prev_d[a[i]] = {-1, -1};
    v[a[i]].push_back(i);
  }

  Tournament T(n + 5);

  llint sol = 0;
  for (int r = 0; r < n; ++r) {
    ++cnt[a[r]];
    T.inc(r, r + 1, INF);
    if (cnt[a[r]] >= 3) {
      int ll = 0, rr = v[a[r]][cnt[a[r]] - 3];
      if (cnt[a[r]] >= 4) ll = v[a[r]][cnt[a[r]] - 4] + 1;
      T.inc(ll, rr + 1, 1);
      auto p = prev_c[a[r]];
      if (p.first != -1) T.inc(p.first, p.second, -1);
      prev_c[a[r]] = {ll, rr + 1};
    }
    int l = 0;
    if (cnt[a[r]] >= 2) l = v[a[r]][cnt[a[r]] - 2] + 1;
    T.inc(l, r + 1, -1);
    auto root = T.get();
    if (root.first == 0) sol += (llint) root.second;
  }

  printf("%lld\n", sol);
  return 0;
}
