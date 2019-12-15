#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

char grid[65][65];

int t, r, s;

bool check_row(int rr) {
  for (int i = 0; i < s; ++i)
    if (grid[rr][i] == 'P') return false;
  return true;
}

bool check_col(int ss) {
  for (int i = 0; i < r; ++i)
    if (grid[i][ss] == 'P') return false;
  return true;
}

void solve() {
  int A = 0, P = 0;
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i) {
    scanf("%s", grid[i]);
    for (int j = 0; j < s; ++j) {
      A += grid[i][j] == 'A';
      P += grid[i][j] == 'P';
    }
  }

  if (A == 0) {
    printf("MORTAL\n");
    return;
  }

  if (P == 0) {
    printf("0\n");
    return;
  }

  if (check_row(0) || check_row(r - 1)) {
    printf("1\n");
    return;
  }

  if (check_col(0) || check_col(s - 1)) {
    printf("1\n");
    return;
  }

  int sol = 4;
  for (int i = 0; i < r; ++i) {
    if (check_row(i)) sol = min(sol, 2);
    if (grid[i][0] == 'A' || grid[i][s - 1] == 'A') {
      if (i == 0 || i == r - 1) sol = min(sol, 2); else sol = min(sol, 3);
    }
    if (i != 0 && i != r - 1) continue;
    bool hasA = false;
    for (int j = 0; j < s; ++j)
      if (grid[i][j] == 'A') hasA = true;

    if (hasA) sol = min(sol, 3);
  }

  for (int j = 0; j < s; ++j) {
    if (check_col(j)) sol = min(sol, 2);
    if (grid[0][j] == 'A' || grid[r - 1][j] == 'A') {
      if (j == 0 || j == s - 1) sol = min(sol, 2); else sol = min(sol, 3);
    }
    if (j != 0 && j != s - 1) continue;
    bool hasA = false;
    for (int i = 0; i < r; ++i)
      if (grid[i][j] == 'A') hasA = true;

    if (hasA) sol = min(sol, 3);
  }
  printf("%d\n", sol);

}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
