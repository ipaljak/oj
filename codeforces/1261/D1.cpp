#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 998244353;
const int MAXN = 2001;

int add(int a, int b) {
  if (a + b < 0) return a + b + MOD;
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

bool bio[MAXN][2*MAXN];

int n, k;
int a[MAXN], memo[MAXN][2*MAXN];

int dp(int i, int diff) {
  if (bio[i][diff + n]) return memo[i][diff + n];
  bio[i][diff + n] = true;
  if (i == n) return memo[i][diff + n] = diff > 0;
  int ret = 0;
  if (a[i] == a[(i + 1) % n]) {
    ret = add(ret, mul(k, dp(i + 1, diff)));
  } else {
    ret = add(ret, dp(i + 1, diff + 1));
    ret = add(ret, dp(i + 1, diff - 1));
    ret = add(ret, mul(k - 2, dp(i + 1, diff)));
  }
  return memo[i][diff + n] = ret;
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  printf("%d\n", dp(0, 0));
  return 0;
}
