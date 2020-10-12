#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int INV2 = 500000004;
const int MAXN = 1e5 + 10;

int n;
int pow2[MAXN], pow11[MAXN], pow10[MAXN];

char s[MAXN];

int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

inline void init() {
  pow2[0] = pow10[0] = pow11[0] = 1;
  for (int i = 1; i < n + 5; ++i) {
    pow2[i] = mul(2, pow2[i - 1]);
    pow10[i] = mul(10, pow10[i - 1]);
    pow11[i] = mul(11, pow11[i - 1]);
  }
}

int main(void) {
  scanf("%s", s); n = strlen(s);
  init();

  int sol = 0, prev = 0;
  for (int i = n - 1; i >= 0; --i) {
    int coef = mul(mul(i, i + 1), INV2);
    sol = add(sol, mul(prev, s[i] - '0'));
    sol = add(sol, mul(mul(coef, pow10[n - 1 - i]), s[i] - '0'));
    prev = add(prev, mul(pow10[n - 1 - i], n - i));
  }

  printf("%d\n", sol);
  return 0;
}
