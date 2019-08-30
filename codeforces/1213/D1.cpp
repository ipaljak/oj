#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n, k;
int a[MAXN];

map<int, vector<int>> m;

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    m[a[i]].push_back(0);
    int cnt = 0;
    while (a[i] > 0) {
      a[i] /= 2;
      ++cnt;
      m[a[i]].push_back(cnt);
    }
  }

  int sol = MOD;
  for (auto &kv : m) {
    if (kv.second.size() < k) continue;
    sort(kv.second.begin(), kv.second.end());
    int curr = 0;
    for (int j = 0; j < k; ++j)
      curr += kv.second[j];
    sol = min(sol, curr);
  }

  printf("%d\n", sol);
  return 0;
}
