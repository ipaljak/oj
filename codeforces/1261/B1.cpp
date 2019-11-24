#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 105;

int n, m;

llint a[MAXN];
llint dp[MAXN][MAXN];

void reconstruct(int k, int pos) {
  int start = -1;
  for (int i = 0; i < n; ++i) {
    if (dp[i][k] == 0) continue;
    if (start == -1) { start = i; continue; }
    if (dp[i][k] == dp[start][k] && a[start] > a[i]) { start = i; continue; }
    if (dp[i][k] > dp[start][k]) { start = i; continue; }
  }
  assert(start != -1);

  for (int i = 1; i < pos; ++i) {
    int nxt = -1;
    for (int j = start + 1; j < n; ++j) {
      if (dp[start][k] != a[start] + dp[j][k - 1]) continue;
      if (nxt == -1 || a[nxt] > a[j]) nxt = j;
    }
    assert(nxt != -1);
    start = nxt;
    --k;
  }
  printf("%lld\n", a[start]);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

  for (int i = 0; i < n; ++i) dp[i][1] = a[i];
  for (int k = 2; k <= n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (dp[j][k - 1] != 0)
          dp[i][k] = max(dp[i][k], a[i] + dp[j][k - 1]);
      }
    }
  }

  //for (int i = 0; i < n; ++i) {
    //for (int j = 1; j <= n; ++j)
      //printf("%d ", dp[i][j]);
    //printf("\n");
  //}
  //return 0;

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int k, pos;
    scanf("%d%d", &k, &pos);
    reconstruct(k, pos);
  }
  return 0;
}
