#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int INF = 1e9 + 10;

class Tournament {
  public:
    int n, offset, from, to;
    vector<int> tree;

    Tournament() {}
    Tournament(int _n) {
      n = _n;
      for (offset = 1; offset <= n; offset *= 2);
      tree.resize(2 * offset, -INF);
    }

    int get_max(int i, int lo, int hi) {
      if (from >= hi || to <= lo) return -INF;
      if (lo >= from && hi <= to) return tree[i];
      return max(get_max(2 * i, lo, (lo + hi) / 2),
                 get_max(2 * i + 1, (lo + hi) / 2, hi));
    }

    void set(int i, int val) {
      i += offset; tree[i] = val; i /= 2;
      while (i > 0) {
        tree[i] = max(tree[2*i], tree[2*i+1]);
        i /= 2;
      }
    }

    int get_max(int lo, int hi) {
      from = lo; to = hi;
      return get_max(1, 0, offset);
    }
};

int n, w;
llint pref_sol[MAXN];

void solve(vector<int> &v) {
  Tournament T(v.size());
  for (int i = 0; i < (int) v.size(); ++i)
    T.set(i, v[i]);
  if (2 * (int) v.size() >= w) {
    for (int i = 0; i < w; ++i) {
      int curr = -INF;
      if (i >= (int) v.size() || i < w - (int) v.size()) curr = 0;
      int L = 0, R = (int) v.size() - 1;
      if (w - i <= (int) v.size())
        L = (int) v.size() - (w - i);
      if (i + 1 <= (int) v.size())
        R = i;
      curr = max(curr, T.get_max(L, R + 1));
      pref_sol[i] += (llint) curr;
      pref_sol[i + 1] -= (llint) curr;
    }
  } else {
    for (int i = 0; i < (int) v.size(); ++i) {
      int currL = 0, currR = 0;
      currL = max(currL, T.get_max(0, i + 1));
      currR = max(currR, T.get_max((int) v.size() - i - 1, (int) v.size()));
      pref_sol[i] += (llint) currL;
      pref_sol[i + 1] -= (llint) currL;
      pref_sol[w - i - 1] += (llint) currR;
      pref_sol[w - i] -= (llint) currR;
    }
    int curr = max(0, T.get_max(0, (int) v.size()));
    pref_sol[(int) v.size()] += (llint) curr;
    pref_sol[w - (int) v.size()] -= (llint) curr;
  }
}

int main(void) {
  scanf("%d%d", &n, &w);
  for (int i = 0; i < n; ++i) {
    int l; scanf("%d", &l);
    vector<int> v(l);
    for (int j = 0; j < l; ++j)
      scanf("%d", &v[j]);
    solve(v);
  }

  llint curr = 0;
  for (int i = 0; i < w; ++i) {
    curr += pref_sol[i];
    printf("%lld ", curr);
  }

  printf("\n");
  return 0;
}
