#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

const int dr[] = {0, -1, 0, +1};
const int ds[] = {+1, 0, -1, 0};

bool bio[MAXN][MAXN];

int r, s;
char grid[MAXN][MAXN];

void dfs(int rr, int ss) {
  bio[rr][ss] = true;
  for (int i = 0; i < 4; ++i) {
    int rrr = rr + dr[i], sss = ss + ds[i];
    if (rrr >= 0 && rrr < r && sss >= 0 && sss < s && grid[rrr][sss] == '#' &&
        !bio[rrr][sss]) {
      dfs(rrr, sss);
    }
  }
}

int main(void) {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i)
    scanf("%s", grid[i]);

  bool ok = true;
  int wr = 0, wc = 0;
  for (int i = 0; i < r; ++i) {
    int black = 0;
    for (int j = 0; j < s; ++j) {
      if (grid[i][j] == '#' && (j == 0 || grid[i][j - 1] == '.')) ++black;
    }
    wr += black == 0;
    ok &= black < 2;
  }

  for (int j = 0; j < s; ++j) {
    int black = 0;
    for (int i = 0; i < r; ++i) {
      if (grid[i][j] == '#' && (i == 0 || grid[i - 1][j] == '.')) ++black;
    }
    wc += black == 0;
    ok &= black < 2;
  }

  ok &= !(min(wr, wc) == 0 && max(wr, wc) > 0);

  if (!ok) {
    printf("-1\n");
    return 0;
  }

  int sol = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      if (grid[i][j] == '#' && !bio[i][j]) {
        ++sol;
        dfs(i, j);
      }
    }
  }

  printf("%d\n", sol);
  return 0;
}
