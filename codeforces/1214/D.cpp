#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

const int p[] = {32452867, 122949823, 198491329};

bool bio[MAXN];

int n, m;

inline bool inside(int r, int s) {
  return r >= 0 && r < n && s >= 0 && s < m;
}

inline int add(int a, int b, int mod) {
  if (a + b >= mod) return  a + b - mod;
  if (a + b < 0) return a + b + mod;
  return a + b;
}

inline int mul(int a, int b, int mod) {
  return (llint) a * b % mod;
}

int main(void) {
  scanf("%d%d", &n, &m);
  char grid[n + 1][m + 1];
  for (int i = 0; i < n; ++i)
    scanf("%s", grid[i]);

  vector<int> dp1[n + 1][m + 1], dp2[n + 1][m + 1];
  dp1[0][0] = {1, 1, 1};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) continue;
      dp1[i][j] = {0, 0, 0};
      if (grid[i][j] == '#') continue;
      for (int k = 0; k < 3; ++k) {
        if (inside(i - 1, j)) dp1[i][j][k] = add(dp1[i][j][k], dp1[i - 1][j][k], p[k]);
        if (inside(i, j - 1)) dp1[i][j][k] = add(dp1[i][j][k], dp1[i][j - 1][k], p[k]);
      }
    }
  }

  dp2[n - 1][m - 1] = {1, 1, 1};
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (i == n - 1 && j == m - 1) continue;
      dp2[i][j] = {0, 0, 0};
      if (grid[i][j] == '#') continue;
      for (int k = 0; k < 3; ++k) {
        if (inside(i + 1, j)) dp2[i][j][k] = add(dp2[i][j][k], dp2[i + 1][j][k], p[k]);
        if (inside(i, j + 1)) dp2[i][j][k] = add(dp2[i][j][k], dp2[i][j + 1][k], p[k]);
      }
    }
  }

  bool flag = true;
  for (int i = 0; i < 3; ++i)
    flag &= dp1[n - 1][m - 1][i] == 0;

  if (flag) {
    printf("0\n");
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i == 0 && j == 0) continue;
      if (i == n - 1 && j == m - 1) continue;
      if (grid[i][j] != '.') continue;
      bool flag = true;
      for (int k = 0; k < 3; ++k) {
        flag &= mul(dp1[i][j][k], dp2[i][j][k], p[k]) == dp1[n - 1][m - 1][k];
      }
      if (flag) {
        //TRACE(i _ j);
        printf("1\n");
        return 0;
      }
    }
  }


  printf("2\n");

  return 0;
}
