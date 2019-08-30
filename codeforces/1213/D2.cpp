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

void m_insert(int k, int v) {
  if (m.find(k) == m.end()) {
    m[k] = vector<int>(20, 0);
  }
  m[k][v]++;
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    m_insert(a[i], 0);
    int cnt = 0;
    while (a[i] > 0) {
      a[i] /= 2;
      ++cnt;
      m_insert(a[i], cnt);
    }
  }

  int sol = MOD;
  for (auto &kv : m) {
    int curr = 0, left = k;
    for (int j = 0; j < 20; ++j) {
      if (left == 0) continue;
      curr += j * min(left, kv.second[j]);
      left -= min(left, kv.second[j]);
    }
    if (left == 0)
      sol = min(sol, curr);
  }

  printf("%d\n", sol);
  return 0;
}
