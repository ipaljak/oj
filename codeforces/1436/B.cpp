#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, n;

void solve() {
  scanf("%d", &n);
  if (n % 2 == 0) {
    int x = 103 - (n - 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) printf("%d ", x); else printf("1 ");
      }
      printf("\n");
    }
  } else {
    int x = 107 - (n - 1) - 3;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) { printf("%d ", x); continue; }
        if ((i + 1) % n == j) { printf("4 "); continue; }
        printf("1 ");
      }
      printf("\n");
    }
  }
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
