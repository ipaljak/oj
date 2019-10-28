#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, k;
int a[MAXN];

map<vector<pair<int, int>>, int> cnt;

int main(void) {
  scanf("%d%d", &n, &k);
  llint sol = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    vector<pair<int, int>> fact, rfact;
    int x = a[i];
    for (int j = 2; j * j <= x; ++j) {
      if (x % j != 0) continue;
      int e = 0;
      while (x % j == 0) {
        x /= j;
        ++e;
      }
      if (e % k != 0) {
        fact.emplace_back(j, e % k);
        rfact.emplace_back(j, k - (e % k));
      }
    }
    if (x != 1) {
      if (1 % k != 0) {
        fact.emplace_back(x, 1 % k);
        rfact.emplace_back(x, k - (1 % k));
      }
    }
    sol += (llint) cnt[rfact];
    cnt[fact]++;
  }

  printf("%lld\n", sol);
  return 0;
}
