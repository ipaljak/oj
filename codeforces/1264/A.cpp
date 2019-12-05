#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 4e5 + 10;

int t, n;
int p[MAXN];

vector<pair<int, int>> v;

void solve() {
  v.clear();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &p[i]);

  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (p[i] == p[i - 1]) { ++cnt; continue; }
    v.emplace_back(p[i - 1], cnt);
    cnt = 1;
  }

  v.emplace_back(p[n - 1], cnt);
  //for (auto p : v)
    //TRACE(p.first _ p.second);

  //return;

  int g = v[0].second, s = 0, b = 0, total = v[0].second;
  for (int i = 1; i < (int) v.size(); ++i) {
    total += v[i].second;
    if (2 * total > n) break;
    if (g >= s) { s += v[i].second; continue; }
    b += v[i].second;
  }

  if (g < s && g < b) {
    printf("%d %d %d\n", g, s, b);
  } else {
    printf("0 0 0\n");
  }
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
