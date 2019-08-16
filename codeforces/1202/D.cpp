#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, n;

void solve() {
  scanf("%d", &n);
  int k = 1e5;
  while ((llint) k * (k - 1) / 2 > (llint) n) --k;
  printf("1");
  n -= k * (k - 1) / 2;
  for (int i = k; i > 0; --i) {
    while (i * (i - 1) / 2 <= n && n != 0) {
      printf("1");
      n -= i * (i - 1) / 2;
    }
    printf("3");
  }
  printf("7\n");
}

int main(void) {
  scanf("%d", &t);
  while (t --> 0) solve();
  return 0;
}
