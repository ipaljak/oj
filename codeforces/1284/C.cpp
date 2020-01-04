#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 250010;

int n, m;
int fact[MAXN];

int add(int a, int b) {
  if (a + b < 0) return a + b + m;
  if (a + b >= m) return a + b - m;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % m;
}

int main(void) {
  scanf("%d%d", &n, &m);

  fact[0] = 1;
  for (int i = 1; i <= n; ++i)
    fact[i] = mul(i, fact[i - 1]);

  int sol = 0;
  for (int k = 1; k <= n; ++k) {
    sol = add(sol, mul(n - k + 1, mul(n - k + 1, mul(fact[k], fact[n - k]))));
  }

  printf("%d\n", sol);
  return 0;
}
