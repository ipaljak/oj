#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
int x[MAXN], y[MAXN], sx[MAXN], sy[MAXN];

int cnt[MAXN];
map<int, vector<int>> my;

struct Tournament {
  public:
    vector<int> tree;
    int offset, from, to;

    Tournament(int n) {
      for (offset = 1; offset <= n; offset *= 2);
      tree.resize(2 * offset);
    }

    void set(int i, int val) {
      i += offset; tree[i] = val; i /= 2;
      while (i > 0) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
        i /= 2;
      }
    }

    int sum(int node, int lo, int hi) {
      if (hi <= from || to <= lo) return 0;
      if (lo >= from && hi <= to) return tree[node];
      return sum(2 * node, lo, (lo + hi) / 2) +
             sum(2 * node + 1, (lo + hi) / 2, hi);
    }

    int sum(int lo, int hi) {
      from = lo; to = hi;
      if (lo >= hi) return 0;
      return sum(1, 0, offset);
    }
};

void sazmi() {
  map<int, int> sazx, sazy;
  sort(sx, sx + n); sort(sy, sy + n);
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && sx[i] == sx[i - 1]) continue;
    sazx[sx[i]] = curr++;
  }
  curr = 0;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && sy[i] == sy[i - 1]) continue;
    sazy[sy[i]] = curr++;
  }
  for (int i = 0; i < n; ++i) x[i] = sazx[x[i]];
  for (int i = 0; i < n; ++i) y[i] = sazy[y[i]];
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    sx[i] = x[i]; sy[i] = y[i];
  }

  sazmi();
  Tournament T(MAXN);

  for (int i = 0; i < n; ++i) {
    if (cnt[x[i]] == 0) T.set(x[i], 1);
    ++cnt[x[i]];
  }

  for (int i = 0; i < n; ++i)
    my[y[i]].push_back(x[i]);

  llint sol = 0;
  for (auto &p : my) {
    int tot_x = T.sum(0, MAXN);
    sol += (llint) tot_x * (tot_x + 1) / 2LL;
    sort(p.second.begin(), p.second.end());
    int A = T.sum(0, p.second[0]),
        B = T.sum(p.second[p.second.size() - 1] + 1, MAXN);
    //TRACE(p.second[0] _ p.second[p.second.size() - 1] _ A _ B);
    sol -= (llint) A * (A + 1) / 2LL;
    sol -= (llint) B * (B + 1) / 2LL;
    for (int i = 0; i < (int) p.second.size(); ++i) {
      int xx = p.second[i];
      --cnt[xx];
      if (cnt[xx] == 0)
        T.set(xx, 0);
      if (i != 0) {
        int C = T.sum(p.second[i - 1] + 1, p.second[i]);
        sol -= (llint) C * (C + 1) / 2LL;
      }
    }
    ////TRACE(sol);
  }

  printf("%lld\n", sol);
  return 0;
}
