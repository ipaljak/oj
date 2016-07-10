#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int mod = 1e6 + 3;

struct matrix {
  int mat[110][110];
  matrix () {
    memset(mat, 0, sizeof mat);
  }
} sol, X, B;

int n, w, h;

inline int add(int a, int b) {
  return (a + b + mod) % mod;  
}

inline int mul(int a, int b) {
  return (llint) a * b % mod; 
}

matrix operator * (const matrix &A, const matrix &B) {
  
  matrix ret; 

  for (int i = 0; i < w + 1; ++i) {
    for (int j = 0; j < w + 1; ++j) {
      for (int k = 0; k < w + 1; ++k) {
        ret.mat[i][j] = add(ret.mat[i][j], mul(A.mat[i][k], B.mat[k][j]));  
      }
    }
  } 

  return ret;

}

inline void init() {

  for (int i = 0; i < w + 1; ++i)
    sol.mat[i][i] = 1;

  B.mat[0][0] = 1;

  for (int i = 0; i < w + 1; ++i)
    X.mat[i][0] = 1;

  for (int j = 1; j < w + 1; ++j)
    X.mat[j - 1][j] = h;

}

int main(void) {

  scanf("%d%d%d", &n, &w, &h);

  init();
  while (n > 0) {
    if (n & 1) sol = sol * X;
    n >>= 1; X = X * X;
  }
  
  sol = B * sol;

  int ans = 0;
  for (int i = 0; i < w + 1; ++i)
    ans = add(ans, sol.mat[0][i]);

  printf("%d\n", ans);
  return 0;

}

