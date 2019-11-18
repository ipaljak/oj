#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int t, n, m;
int a[MAXN], suff[MAXN];

vector<pair<int, int>> v;

int binary(int power) {
  int lo = 0, hi = m - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (v[mid].first < power) lo = mid + 1; else hi = mid;
  }
  return suff[lo];
}

void solve() {
  scanf("%d", &n);
  int maxp = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    maxp = max(maxp, a[i]);
  }
  scanf("%d", &m); v.clear();
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b);
    maxp = max(maxp, a);
    v.emplace_back(a, b);
  }

  sort(v.begin(), v.end());
  suff[m - 1] = v.back().second;
  for (int i = m - 2; i >= 0; --i)
    suff[i] = max(suff[i + 1], v[i].second);

  if (maxp > v.back().first) {
    printf("-1\n");
    return;
  }

  int curr = 0, lst = -1, sol = 1;
  for (int i = 0; i < n; ++i) {
    curr = max(curr, a[i]);
    int ss = binary(curr);
    if (ss >= i - lst) continue;
    ++sol; lst = i - 1; curr = a[i];
  }

  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
