#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 510;

int r, s;
int a[MAXN][MAXN], b[MAXN][MAXN];

int main(void) {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < s; ++j)
      scanf("%d", &a[i][j]);
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < s; ++j)
      scanf("%d", &b[i][j]);

  {
    bool pa = 0, pb = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < s; ++j) {
        pa ^= a[i][j];
        pb ^= b[i][j];
      }
    }
    if (pa != pb) { printf("No\n"); return 0; }
  }

  for (int i = 0; i < r; ++i) {
    bool pa = 0, pb = 0;
    for (int j = 0; j < s; ++j) {
      pa ^= a[i][j];
      pb ^= b[i][j];
    }
    if (pa != pb) { printf("No\n"); return 0; }
  }

  for (int j = 0; j < s; ++j) {
    bool pa = 0, pb = 0;
    for (int i = 0; i < r; ++i) {
      pa ^= a[i][j];
      pb ^= b[i][j];
    }
    if (pa != pb) { printf("No\n"); return 0; }
  }

  printf("Yes\n");
  return 0;
}
