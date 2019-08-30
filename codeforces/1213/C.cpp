#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int q;

void solve() {
  llint n, m;
  scanf("%lld%lld", &n, &m);
  if (m > n) { printf("0\n"); return; }
  llint k = n / m;

  vector<int> v;
  llint last = 0, sum = 0;
  for (int i = 0; i < k; ++i) {
    last = (last + m) % 10;
    if (find(v.begin(), v.end(), last) != v.end()) break;
    v.emplace_back(last);
    sum += last;
  }

  llint sol = sum * (k / (llint) v.size());
  for (int i = 0; i < k % v.size(); ++i)
    sol += (llint) v[i];

  printf("%lld\n", sol);
}

int main(void) {
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}
