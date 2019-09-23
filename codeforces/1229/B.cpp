#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int p[MAXN];
llint x[MAXN];

vector<int> v[MAXN];
map<pair<int, llint>, int> memo;

inline int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

inline int mymod(llint a) {
  if (a < (llint) MOD) return a;
  return a % MOD;
}

int dp(int node, int dad, llint g) {
  p[node] = dad;
  if (memo.find({node, g}) != memo.end())
    return memo[{node, g}];
  llint gg = __gcd(g, x[node]);
  int ret = mymod(gg);
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    ret = add(ret, dp(nxt, node, gg));
  }
  return memo[{node, g}] = ret;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &x[i]);
  for (int i = 0; i < n - 1; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int sol = dp(0, -1, 0);
  for (int i = 1; i < n; ++i) {
    sol = add(sol, dp(i, p[i], 0));
  }

  printf("%d\n", sol);
  return 0;
}
