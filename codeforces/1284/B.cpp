#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;
const int MAXL = 1e6 + 10;

bool desc[MAXN];

int n;
int cnt[MAXL];
vector<int> v[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      int y; scanf("%d", &y);
      v[i].push_back(y);
    }
    desc[i] = true;
    for (int j = 1; j < x; ++j)
      desc[i] &= v[i][j - 1] >= v[i][j];
    if (desc[i]) cnt[v[i][0]]++;
  }

  for (int i = 1; i < MAXL; ++i)
    cnt[i] += cnt[i - 1];

  llint sol = (llint) n * n;
  for (int i = 0; i < n; ++i) {
    if (!desc[i]) continue;
    sol -= (llint) cnt[v[i][v[i].size() - 1]];
  }

  printf("%lld\n", sol);
  return 0;
}
