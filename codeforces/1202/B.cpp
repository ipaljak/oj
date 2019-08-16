#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 10;
const int INF = 1e9 + 10;

int n;
int dist[11][11];
char s[MAXN];

int solve(int x, int y) {
  memset(dist, -1, sizeof dist);
  for (int i = 0; i < 10; ++i) {
    int d[11];
    for (int k = 0; k < 10; ++k) d[k] = INF;
    d[i] = 0;
    for (int k = 0; k < 10; ++k) {
      for (int j = 0; j < 10; ++j) {
        d[j] = min(d[j], 1 + d[(j - x + 10) % 10]);
        d[j] = min(d[j], 1 + d[(j - y + 10) % 10]);
      }
    }
    d[i] = min(1 + d[(i - x + 10) % 10], 1 + d[(i - y + 10) % 10]);
    for (int j = 0; j < 10; ++j) dist[i][j] = d[j];
  }
  int ret = 0;
  for (int i = 1; i < n; ++i) {
    int d = dist[s[i - 1] - '0'][s[i] - '0'];
    if (d == INF) return -1;
    ret += d - 1;
  }
  return ret;
}

int main(void) {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j)
      printf("%d ", solve(i, j));
    printf("\n");
  }
  return 0;
}
