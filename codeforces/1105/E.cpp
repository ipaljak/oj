#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 41;

int n, m;
int adj[MAXN][MAXN];

llint neigh[MAXN];

map<string, int> id;
unordered_map<llint, int> memo;

void add_edges(const set<string> &s) {
  for (const auto &a : s) {
    for (const auto &b : s) {
      int aa = id[a], bb = id[b];
      adj[aa][bb] = 1;
    }
  }
}

int max_clique(llint mask) {
  if (memo.find(mask) != memo.end()) return memo[mask];
  if (mask == 0) return memo[mask] = 0;
  int x = 0;
  while ((mask & (1LL << x)) == 0) ++x;
  return memo[mask] = max(max_clique(mask - (1LL << x)),
                          1 + max_clique(neigh[x] & mask));
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  set<string> curr;
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      add_edges(curr);
      curr.clear();
    } else {
      string s;
      cin >> s;
      curr.insert(s);
      if (id.find(s) == id.end()) {
        id[s] = (int) id.size();
      }
    }
  }
  add_edges(curr);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (adj[i][j] == 0)
        neigh[i] |= 1LL << j;

  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j < n; ++j)
      //printf("%d", adj[i][j]);
    //printf("\n");
  //}

  //for (llint m = 0; m < 1LL << (n - (n / 2)); ++m) max_clique(m << (n / 2));

  int sol = 0;
  for (llint m = 0; m < 1LL << (n / 2); ++m) {
    if (max_clique(m) != __builtin_popcount(m)) continue;
    llint mm = ((1LL << (n - (n / 2))) - 1) << (n / 2);
    for (int i = 0; i < n / 2; ++i) {
      if ((m & (1LL << i)) == 0) continue;
      mm &= neigh[i];
    }
    sol = max(sol, memo[m] + max_clique(mm));
  }

  cout << sol << "\n";
  return 0;
}
