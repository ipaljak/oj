#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, root;
int k[MAXN];

llint sol[MAXN];

vector<int> v[MAXN];

inline bool cmp(const int &a, const int &b) {
  return sol[a] > sol[b];
}

void solve(int node, int dad) {
  k[node] -= node != root;
  sol[node] += node != root;
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    solve(nxt, node);
  }

  sort(v[node].begin(), v[node].end(), cmp);
  llint tot = 0;
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    if (k[node] > 0) {
      sol[node] += sol[nxt] + 1;
      k[node]--;
    }
    tot += (llint) k[nxt];
  }

  sol[node] += 2LL * min(tot, (llint) k[node]);
  k[node] -= min(tot, (llint) k[node]);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &k[i]);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  scanf("%d", &root); --root;

  solve(root, -1);
  printf("%lld\n", sol[root]);

  return 0;
}
