#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int r, s;
    scanf("%d%d", &r, &s);
    bool row[55], col[55];
    memset(row, false, sizeof row);
    memset(col, false, sizeof col);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < s; ++j) {
        int x;
        scanf("%d", &x);
        if (x) row[i] = col[j] = true;
      }
    }
    int rr = 0, ss = 0;
    for (int i = 0; i < r; ++i) rr += !row[i];
    for (int i = 0; i < s; ++i) ss += !col[i];
    if (min(rr, ss) % 2 == 1)
      printf("Ashish\n");
    else
      printf("Vivek\n");
  }
  return 0;
}
