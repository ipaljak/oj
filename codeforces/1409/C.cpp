#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, n, x, y;

bool calc(int diff) {
  vector<int> v;
  v.emplace_back(x);
  for (int i = x + diff; i <= y && v.size() < n + 10 ; i += diff)
    v.emplace_back(i);

  int xx = x - diff;
  while (xx > 0 && v.size() < n) {
    v.emplace_back(xx);
    xx -= diff;
  }

  xx = y + diff;
  while (v.size() < n) {
    v.emplace_back(xx);
    xx += diff;
  }

  if (v.size() != n) return false;

  sort(v.begin(), v.end());
  for (int x : v) printf("%d ", x);
  printf("\n");
}

void solve() {
  scanf("%d%d%d", &n, &x, &y);
  int diff = y - x;
  for (int i = 1; i <= diff; ++i)
    if (diff % i == 0 && calc(i)) break;
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
