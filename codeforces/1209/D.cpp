#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

bool bio[MAXN];

int n, k;
vector<int> v[MAXN];

void dfs(int node) {
  bio[node] = true;
  for (int nxt : v[node])
    if (!bio[nxt])
      dfs(nxt);
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y); --x; --y;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }

  int lucky = n;
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    dfs(i); --lucky;
  }

  assert(lucky <= k);
  printf("%d\n", k - lucky);
  return 0;
}
