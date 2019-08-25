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
  for (int i = 0; i < t; ++i) {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    if (n % 3 == 0) printf("%d\n", a);
    if (n % 3 == 1) printf("%d\n", b);
    if (n % 3 == 2) printf("%d\n", a ^ b);
  }
  return 0;
}
