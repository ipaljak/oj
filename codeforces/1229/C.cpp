#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, m, q;
int lo[MAXN];

vector<int> v[MAXN];
vector<int> hi[MAXN];

inline llint calc(int i) {
  llint ret = 0;
  llint los = (llint) lo[i];
  llint his = (llint) hi[i].size();
  ret += los * (los - 1) / 2;
  ret += his * (his - 1) / 2;
  return ret;
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    if (a > b) swap(a, b);
    v[a].push_back(b);
    v[b].push_back(a);
    hi[a].push_back(b);
    ++lo[b];
    //lo[b].insert(a);
  }

  llint tot = 0;
  llint ok = 0;
  for (int i = 0; i < n; ++i) {
    llint deg = (llint) v[i].size();
    tot += deg * (deg - 1) / 2;
    ok += calc(i);
  }

  scanf("%d", &q);

  printf("%lld\n", tot - ok);
  for (int i = 0; i < q; ++i) {
    int x; scanf("%d", &x); --x;
    ok -= calc(x);
    for (int y : hi[x]) {
      ok -= calc(y);
      ++lo[x];
      //lo[x].insert(y);
      --lo[y];
      //lo[y].erase(x);
      hi[y].push_back(x);
      ok += calc(y);
    }
    hi[x].clear();
    ok += calc(x);
    printf("%lld\n", tot - ok);
  }

  return 0;
}
