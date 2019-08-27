#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 101;
const int MAXM = 1e6 + 10;

int n, m;
int p[MAXM], dist[MAXN][MAXN], p_dist[MAXN];

void floyd() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (dist[i][j] == 0 && i != j) dist[i][j] = 2000;
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    char s[MAXN];
    scanf("%s", s);
    for (int j = 0; j < n; ++j) {
      if (s[j] == '1') dist[i][j] = 1;
    }
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &p[i]); --p[i];
  }

  floyd();

  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j < n; ++j)
      //printf("%d ", dist[i][j]);
    //printf("\n");
  //}

  vector<int> ans;
  p_dist[p[0]] = 0;
  ans.push_back(p[0]);

  for (int i = 1; i < m; ++i) {
    if (dist[ans[ans.size() - 1]][p[i]] <
        i - p_dist[ans[ans.size() - 1]])
      ans.push_back(p[i - 1]);
    p_dist[p[i]] = i;
  }

  ans.push_back(p[m - 1]);

  printf("%d\n", (int) ans.size());
  for (int x : ans) printf("%d ", x + 1);
  printf("\n");

  return 0;
}
