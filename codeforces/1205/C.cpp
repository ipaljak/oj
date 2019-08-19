#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 55;

const int dr[] = {1, 0};
const int ds[] = {0, 1};

int n, q;
int mat[MAXN][MAXN], mat1[MAXN][MAXN];
int memo[MAXN][MAXN][MAXN][MAXN], memo1[MAXN][MAXN][MAXN][MAXN];

bool ask(int r1, int s1, int r2, int s2) {
  ++q;
  assert(q <= n * n);
  printf("? %d %d %d %d\n", r1 + 1, s1 + 1, r2 + 1, s2 + 1);
  fflush(stdout);
  int x; scanf("%d", &x);
  return x;
}

bool inside(int r, int s) {
  return r >= 0 && r < n && s >= 0 && s < n;
}

void ans(int (&mat)[MAXN][MAXN]) {
  printf("!\n");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
  fflush(stdout);
  exit(0);
}

int dp(int r1, int s1, int r2, int s2, int (&mat)[MAXN][MAXN],
        int (&memo)[MAXN][MAXN][MAXN][MAXN]) {
  if (!inside(r1, s1) || !inside(r2, s2)) return 0;
  if (memo[r1][s1][r2][s2] != -1) return memo[r1][s1][r2][s2];
  if (abs(r1 - r2) + abs(s1 - s2) < 2)
    return memo[r1][s1][r2][s2] = mat[r1][s1] == mat[r2][s2];
  if (mat[r1][s1] != mat[r2][s2] || r2 < r1 || s2 < s1)
    return memo[r1][s1][r2][s2] = 0;
  int ans = 0;
  ans |= dp(r1 + 1, s1, r2 - 1, s2, mat, memo);
  ans |= dp(r1 + 1, s1, r2, s2 - 1, mat, memo);
  ans |= dp(r1, s1 + 1, r2 - 1, s2, mat, memo);
  ans |= dp(r1, s1 + 1, r2, s2 - 1, mat, memo);
  return memo[r1][s1][r2][s2] = ans;
}

int main(void) {
  scanf("%d", &n);
  mat[0][0] = 1;
  mat[n - 1][n - 1] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = (i % 2); j < n; j += 2) {
      if (i % 2 == 0) {
        if (i == 0 && j == 0) continue;
        if (j != 0)
          mat[i][j] = ask(i, j - 2, i, j) ^ (1 - mat[i][j - 2]);
        else
          mat[i][j] = ask(i - 2, j, i, j) ^ (1 - mat[i - 2][j]);
      } else {
        if (j == 1)
          mat[i][j] = ask(i - 1, j - 1, i, j) ^ (1 - mat[i - 1][j - 1]);
        else
          mat[i][j] = ask(i, j - 2, i, j) ^ (1 - mat[i][j - 2]);
      }
    }
  }

  mat[0][1] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = (i % 2) + 1; j < n; j += 2) {
      if (i % 2 == 0) {
        if (i == 0 && j == 1) continue;
        if (j != 1)
          mat[i][j] = ask(i, j - 2, i, j) ^ (1 - mat[i][j - 2]);
        else
          mat[i][j] = ask(i - 2, j, i, j) ^ (1 - mat[i - 2][j]);
      } else {
        if (j == 2) {
          mat[i][j] = ask(i - 1, j - 1, i, j) ^ (1 - mat[i - 1][j - 1]);
        } else {
          mat[i][j] = ask(i, j - 2, i, j) ^ (1 - mat[i][j - 2]);
        }
      }
    }
  }

  for (int i = 1; i < n; i += 2)
    mat[i][0] = ask(i, 0, i, 2) ^ (1 - mat[i][2]);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if ((i + j) % 2 == 0)
        mat1[i][j] = mat[i][j];
      else
        mat1[i][j] = 1 - mat[i][j];

  //printf("Mat:\n");
  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j < n; ++j)
      //printf("%d ", mat[i][j]);
    //printf("\n");
  //}

  //printf("Mat1:\n");
  //for (int i = 0; i < n; ++i) {
    //for (int j = 0; j < n; ++j)
      //printf("%d ", mat1[i][j]);
    //printf("\n");
  //}
  memset(memo, -1, sizeof memo);
  memset(memo1, -1, sizeof memo1);

  for (int r1 = 0; r1 < n; ++r1) {
    for (int s1 = 0; s1 < n; ++s1) {
      for (int r2 = r1; r2 < n; ++r2) {
        for (int s2 = s1; s2 < n; ++s2) {
          if (abs(r1 - r2) + abs(s1 - s2) < 2) continue;
          dp(r1, s1, r2, s2, mat, memo);
          dp(r1, s1, r2, s2, mat1, memo1);
          if (memo[r1][s1][r2][s2] != memo1[r1][s1][r2][s2]) {
            if (ask(r1, s1, r2, s2) == memo[r1][s1][r2][s2])
              ans(mat);
            else
              ans(mat1);
          }
        }
      }
    }
  }

  assert(false);
  return 0;
}
