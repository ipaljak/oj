#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 110;

int t, r, s, k;
char grid[MAXN][MAXN];
char ret[MAXN][MAXN];

string chars;

void solve() {
  scanf("%d%d%d", &r, &s, &k);
  int cnt = 0;
  for (int i = 0; i < r; ++i) {
    scanf("%s", grid[i]);
    for (int j = 0; j < s; ++j) cnt += grid[i][j] == 'R';
  }

  int x = cnt % k;
  int cc = cnt;
  int ii = 0, jj = 0, curr = 0, ch_ptr = 0;
  while (ii < r) {
    curr += grid[ii][jj] == 'R';
    ret[ii][jj] = chars[ch_ptr];
    if ((x > 0 && curr == cc / k + 1) ||
        (x <= 0 && curr == cc / k)) {
      cnt -= curr;
      --x;
      if (cnt != 0) ++ch_ptr;
      curr = 0;
    }
    if (ii % 2 == 0) ++jj; else --jj;
    if (jj == s) { jj = s - 1; ++ii; }
    if (jj == -1) { jj = 0; ++ii; }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < s; ++j)
      printf("%c", ret[i][j]);
    printf("\n");
  }
  //printf("\n");
}

int main(void) {
  for (char i = '0'; i <= '9'; ++i) chars += i;
  for (char i = 'a'; i <= 'z'; ++i) chars += i;
  for (char i = 'A'; i <= 'Z'; ++i) chars += i;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
