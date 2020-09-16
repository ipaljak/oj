#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 55;

int t, n;
int a[2 * MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);

  vector<int> sol;
  int pt = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (pt == sol.size()) {
      sol.emplace_back(a[i]);
      continue;
    }
    if (pt == n || sol[pt] == a[i]) { ++pt; continue; }
    sol.emplace_back(a[i]);
  }

  for (int x : sol) printf("%d ", x);
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
