#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e6 + 10;

char row[MAXN];

int R, S;

vector<vector<int>> grid, pref_grid;

void trace_vec(const vector<vector<int>> &v) {
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) printf("%d ", v[i][j]);
    printf("\n");
  }
}

void build_pref(const vector<vector<int>> &X, vector<vector<int>> &pref_X) {
  for (int i = 0; i < R; ++i) {
    vector<int> r(S, 0);
    pref_X.push_back(r);
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) {
      pref_X[i][j] = X[i][j];
      if (i - 1 >= 0) pref_X[i][j] += pref_X[i - 1][j];
      if (j - 1 >= 0) pref_X[i][j] += pref_X[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0) pref_X[i][j] -= pref_X[i - 1][j - 1];
    }
  }
}

int sum(const vector<vector<int>> &pref, int r1, int s1, int r2, int s2) {
  int ret = pref[r2][s2];
  if (r1 - 1 >= 0) ret -= pref[r1 - 1][s2];
  if (s1 - 1 >= 0) ret -= pref[r2][s1 - 1];
  if (r1 - 1 >= 0 && s1 - 1 >= 0) ret += pref[r1 - 1][s1 - 1];
  return ret;
}

void build_init_state(vector<vector<int>> &init,
                      int t) {
  for (int i = 0; i < R; ++i) {
    vector<int> r(S, 0);
    init.push_back(r);
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) {
      if (i - t < 0 || i + t >= R || j - t < 0 || j + t >= S) continue;
      if (sum(pref_grid, i - t, j - t, i + t, j + t) == (2*t + 1) * (2*t + 1))
        init[i][j] = 1;
    }
  }
}

bool check_init_state(const vector<vector<int>> &init_state, int t) {
  vector<vector<int>> pref_init_state;
  build_pref(init_state, pref_init_state);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j) {
      int r1 = max(0, i - t), r2 = min(R - 1, i + t);
      int s1 = max(0, j - t), s2 = min(S - 1, j + t);
      bool s = sum(pref_init_state, r1, s1, r2, s2) > 0;
      if (s != grid[i][j]) return false;
    }
  }
  return true;
}

bool check(int t) {
  vector<vector<int>> init_state;
  build_init_state(init_state, t);
  //trace_vec(init_state);
  //printf("\n");
  return check_init_state(init_state, t);
}

int main(void) {
  scanf("%d%d", &R, &S);
  for (int i = 0; i < R; ++i) {
    scanf("%s", row);
    grid.push_back({});
    for (int j = 0; j < S; ++j)
      grid.back().push_back(row[j] == 'X');
  }

  //trace_vec(grid);
  build_pref(grid, pref_grid);
  //printf("\n");
  //trace_vec(pref_grid);

  //check(0);
  //for (int i = 0; i < 10; ++i)
    //printf("%d %d\n", i, check(i));

  //return 0;

  int lo = 0, hi = min(R, S);
  while (lo < hi) {
    int mid = (lo + hi) / 2 + 1;
    if (check(mid)) lo = mid; else hi = mid - 1;
  }

  printf("%d\n", lo);
  vector<vector<int>> sol;
  build_init_state(sol, lo);

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < S; ++j)
      if (sol[i][j]) printf("X"); else printf(".");
    printf("\n");
  }
  return 0;
}
