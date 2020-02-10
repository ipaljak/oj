#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

llint a, b;

llint f(llint a, llint b) {
  if (a == 0 || b == 0) return 0;
  if (a == b) return 1;
  if (a < b) return f(b, a);
  return a / b + f(a % b, b);
}

int main(void) {
  scanf("%lld%lld", &a, &b);
  printf("%lld\n", f(a, b));
  return 0;
}
