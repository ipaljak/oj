#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 55;

int r, s;
int a[MAXN][MAXN], b[MAXN][MAXN];

vector<pair<int, int>> moves;

inline bool check(int i, int j) {
  return i + 1 < r && j + 1 < s && a[i][j] == 1 && a[i + 1][j] == 1 &&
         a[i][j + 1] == 1 && a[i + 1][j + 1] == 1;
}

inline bool equal() {
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < s; ++j)
      if (a[i][j] != b[i][j]) return false;
  return true;
}

int main(void) {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < s; ++j)
      scanf("%d", &a[i][j]);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      if (check(i, j)) {
        moves.emplace_back(i, j);
        b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
      }
    }
  }

  if (!equal()) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", (int) moves.size());
  for (auto &p : moves)
    printf("%d %d\n", p.first + 1, p.second + 1);
  return 0;
}
