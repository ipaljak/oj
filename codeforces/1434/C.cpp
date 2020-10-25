#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;
llint a, b, c, d;

llint f(llint x) {
  llint ret = -(x / d + 1) * a;
  if (x - c >= 0 && (x - c - ((x - c) % d)) >= 0) {
    llint lst = (x - c - ((x - c) % d));
    ret += (lst / d + 1) * b * c;
    llint y = x - lst;
    llint s = (y / d) * (d + y);
    if (x - d > lst) ret += s * b;
  } else {
    llint s = (x / d) * (d + x) / 2;
    if (x - d >= 0) ret += s * b;
  }
  return ret;
}

void solve() {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  llint lo = 0, hi = 1e12;
  while (lo < hi) {
    //TRACE(lo _ hi);
    llint mid = (lo + hi) / 2LL + 1;
    if (f(d * mid) > f((d * (mid + 1)))) lo = mid; else hi = mid - 1;
  }

  if (f(lo * d) > f((lo + 1) * d)) ++lo;

  //TRACE("====");
  //for (int i = 0; i < 10; ++i) TRACE(f(i * d));
  //TRACE(lo);

  if (lo >= (llint) 1e12) {
    printf("-1\n");
  } else {
    printf("%lld\n", -f(lo * d));
  }
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
