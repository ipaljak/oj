#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 3e5 + 10;

int n, p, k;

int add(int a, int b) {
  if (a + b >= p) return a + b - p;
  if (a + b < 0) return a + b + p;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % p;
}

map<int, int> cnt;

int main(void) {
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    int val = mul(mul(x, x), mul(x, x));
    val = add(val, -mul(k, x));
    cnt[val]++;
  }

  llint sol = 0;
  for (const auto &p : cnt)
    sol += (llint) p.second * (p.second - 1) / 2;

  printf("%lld\n", sol);
  return 0;
}
