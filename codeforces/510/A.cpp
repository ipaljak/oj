#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int r, s;

int main(void) {
  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j) {
      if (i % 2 == 0) {
        printf("#");
        continue;
      }
      if ((j == 0 && i % 4 == 3) || (j == s - 1 && i % 4 == 1))
        printf("#");
      else
        printf(".");
    }
    printf("\n");
  }
  return 0;
}
