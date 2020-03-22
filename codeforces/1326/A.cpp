#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int t;

int main(void) {
  scanf("%d", &t);
  while (t-- > 0) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
      printf("-1\n");
    } else {
      printf("2");
      for (int i = 0; i < n - 1; ++i)
        printf("3");
      printf("\n");
    }
  }
  return 0;
}
