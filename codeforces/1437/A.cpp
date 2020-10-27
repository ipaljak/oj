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
    int l, r;
    scanf("%d%d", &l, &r);
    if ((double) l >= (double) (r + 1) / 2.0) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
