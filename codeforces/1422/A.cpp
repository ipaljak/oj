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
    llint a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", a + b + c - 1);
  }
  return 0;
}
