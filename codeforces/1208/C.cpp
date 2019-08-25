#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

int n;
int sol[MAXN][MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i += 4)
    for (int j = 0; j < n; j += 4)
      for (int ii = 0; ii < 4; ++ii)
        for (int jj = 0; jj < 4; ++jj)
          sol[i + ii][j + jj] = ii * 4 + jj + ((i / 4) * (n / 4) + j / 4) * 16;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", sol[i][j]);
    }
    printf("\n");
  }
  return 0;
}
