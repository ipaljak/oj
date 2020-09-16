#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int x[3];
    for (int i = 0; i < 3; ++i) scanf("%d", &x[i]);
    sort(x, x + 3); reverse(x, x + 3);
    if (x[0] != x[1]) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    if (x[0] == x[2])
      printf("%d %d %d\n", x[0], x[1], x[2]);
    else
      printf("%d %d %d\n", x[0], x[2], x[2]);
  }
  return 0;
}
