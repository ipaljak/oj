#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 500;

int r, s;
int sol[MAXN][MAXN];

int main(void) {
  scanf("%d%d", &r, &s);

  bool swapped = false;
  if (s == 1) {
    swap(r, s);
    swapped = true;
  }

  if (r == 1 && s == 1) {
    printf("0\n");
    return 0;
  }

  for (int i = 0; i < s; ++i) sol[0][i] = i + 2;
  for (int i = 1; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      sol[i][j] = sol[0][j] * (s + i + 1);
    }
  }

  if (!swapped) {
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < s; ++j)
        printf("%d ", sol[i][j]);
      printf("\n");
    }
  } else {
    for (int i = 0; i < s; ++i) {
      for (int j = 0; j < r; ++j) {
        printf("%d ", sol[j][i]);
      }
      printf("\n");
    }
  }

  return 0;
}
