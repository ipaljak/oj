#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 105;

int t, n;
int a[MAXN], l[MAXN];

void solve() {
  scanf("%d", &n);
  vector<int> v;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &l[i]); l[i] = 1 - l[i];
    if (l[i]) v.emplace_back(a[i]);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int it = 0;
  for (int i = 0; i < n; ++i)
    if (l[i]) a[i] = v[it++];

  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
