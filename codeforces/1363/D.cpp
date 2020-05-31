#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

int t, n, k, mx = 0;
vector<int> v[MAXN];

void init() {
  mx = 0;
  for (int i = 0; i < n; ++i)
    v[i].clear();
}

int ask(vector<int> &v) {
  printf("? %d ", (int) v.size());
  for (int x : v)
    printf("%d ", x);
  printf("\n");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  mx = max(mx, x);
  return x;
}

void ans(vector<int> &sol) {
  printf("! ");
  for (int x : sol) {
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);
  char res[20];
  scanf("%s", res);
  assert(res[0] == 'C');
}

vector<int> mrg(int lo, int hi) {
  vector<int> ret;
  for (int i = lo; i <= hi; ++i)
    for (int x : v[i])
      ret.push_back(x);
  return ret;
}

vector<int> inv(vector<int> &v) {
  vector<int> ret;
  for (int i = 1; i <= n; ++i)
    if (find(v.begin(), v.end(), i) == v.end())
      ret.push_back(i);
  return ret;
}

void solve() {
  scanf("%d%d", &n, &k); init();
  for (int i = 0; i < k; ++i) {
    int c; scanf("%d", &c);
    for (int j = 0; j < c; ++j) {
      int x;
      scanf("%d", &x);
      v[i].push_back(x);
    }
  }

  vector<int> all;
  for (int i = 1; i <= n; ++i)
    all.push_back(i);
  ask(all);

  int lo = 0, hi = k - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    auto left = mrg(lo, mid);
    if (ask(left) == mx) hi = mid; else lo = mid + 1;
  }

  vector<int> sol;
  for (int i = 0; i < k; ++i) {
    if (i != lo) {
      sol.push_back(mx);
    } else {
      auto vv = inv(v[i]);
      sol.push_back(ask(vv));
    }
  }

  ans(sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
