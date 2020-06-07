#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 55;

const int dr[] = {-1, 0, 1, 0};
const int ds[] = {0, -1, 0, 1};

bool bio[MAXN][MAXN];

int t, r, s;
char grid[MAXN][MAXN];

inline bool inside(int rr, int ss) {
  return rr >= 0 && rr < r && ss >= 0 && ss < s;
}

void solve() {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i)
    scanf("%s", grid[i]);

  bool last = false;
  int good = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      good += grid[i][j] == 'G';
      if (grid[i][j] != 'B') continue;
      for (int k = 0; k < 4; ++k) {
        int ii = i + dr[k], jj = j + ds[k];
        if (!inside(ii, jj)) continue;
        if (grid[ii][jj] == 'G') {
          printf("No\n");
          return;
        }
        last |= (ii == r - 1) && (jj == s - 1);
        if (grid[ii][jj] == '.')
          grid[ii][jj] = '#';
      }
    }
  }

  //TRACE(last _ good);

  if (last) {
    if (good > 0) printf("No\n"); else printf("Yes\n");
    return;
  }

  memset(bio, false, sizeof bio);
  bio[r - 1][s - 1] = true;
  queue<pair<int, int>> Q;
  Q.push({r - 1, s - 1});

  while (!Q.empty()) {
    int i = Q.front().first, j = Q.front().second;
    Q.pop();
    for (int k = 0; k < 4; ++k) {
      int ii = i + dr[k], jj = j + ds[k];
      if (!inside(ii, jj) || bio[ii][jj] || grid[ii][jj] == '#') continue;
      bio[ii][jj] = true;
      assert(grid[ii][jj] != 'B');
      good -= grid[ii][jj] == 'G';
      Q.push({ii, jj});
    }
  }

  if (good == 0) printf("Yes\n"); else printf("No\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
