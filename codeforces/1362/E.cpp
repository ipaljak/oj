#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

int t;
int n, p;
int a[MAXN];

inline int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

inline int mul(int a, int b) {
  return (llint) a * b % MOD;
}

int mypow(int a, int b) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = mul(ret, a);
      --b;
    }
    a = mul(a, a);
    b /= 2;
  }
  return ret;
}

void solve() {
  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  if (p == 1) {
    printf("%d\n", n % 2);
    return;
  }
  sort(a, a + n);
  vector<int> v;
  int A = 0, B = 0;
  llint ca = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (ca >= (llint) i + 1) {
      A = add(A, mypow(p, a[i]));
      continue;
    }
    if (i < n - 1 && a[i] != a[i + 1]) {
      int x = a[i + 1];
      while (ca != 0 && ca <= (llint) 2e6 && x > a[i]) {
        ca *= (llint) p;
        --x;
      }
    }
    if (ca > 0) {
      --ca;
      A = add(A, mypow(p, a[i]));
    } else {
      ++ca;
      B = add(B, mypow(p, a[i]));
    }
  }
  printf("%d\n", add(B, -A));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
