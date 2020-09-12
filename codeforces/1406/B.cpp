#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, n;
int a[MAXN];

void solve() {
  scanf("%d", &n);
  vector<int> p, nn;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] > 0) p.push_back(a[i]);
    if (a[i] < 0) nn.push_back(a[i]);
  }
  sort(a, a + n, [](const int &a, const int &b) { return abs(a) < abs(b); });

  llint sol = 1;
  for (int i = 0; i < 5; ++i) sol *= (llint) a[i];

  sort(p.begin(), p.end(),
       [](const int &a, const int &b) { return abs(a) > abs(b); });

  sort(nn.begin(), nn.end(),
       [](const int &a, const int &b) { return abs(a) > abs(b); });

  for (int i = 0; i < 5; i += 2) {
    if (nn.size() < i || p.size() < 5 - i) continue;
    llint curr = 1;
    for (int j = 0; j < i; ++j) curr *= (llint) nn[j];
    for (int j = 0; j < 5 - i; ++j) curr *= (llint) p[j];
    sol = max(sol, curr);
  }

  printf("%lld\n", sol);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
