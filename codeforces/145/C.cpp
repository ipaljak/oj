#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, k, other;
int a[MAXN], dp[1200][1200], fact[MAXN];

map<int, int> cnt;

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
  while (b) {
    if (b & 1) {
      ret = mul(ret, a);
      b--;
    }
    a = mul(a, a);
    b /= 2;
  }
  return ret;
}

inline int moddiv(int a, int b) {
  return mul(a, mypow(b, MOD - 2));
}

inline int choose(int n, int k) {
  return moddiv(fact[n], mul(fact[k], fact[n - k]));
}

inline void init() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = mul(fact[i - 1], i);
}

bool is_lucky(int x) {
  while (x) {
    if (x % 10 != 7 && x % 10 != 4) return false;
    x /= 10;
  }
  return true;
}

int main(void) {
  init();
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (is_lucky(a[i]))
      cnt[a[i]]++;
    else
      other++;
  }

  for (int i = 0; i <= (int) cnt.size(); ++i) dp[0][i] = 1;
  for (int i = 1; i <= (int) cnt.size(); ++i) {
    int j = 1;
    for (const auto &p : cnt) {
      dp[i][j] = add(dp[i][j - 1], mul(p.second, dp[i - 1][j - 1]));
      ++j;
    }
  }

  int sol = 0;
  for (int i = 0; i <= k; ++i) {
    if (i > (int) cnt.size()) break;
    if (k - i > other) continue;
    sol = add(sol, mul(dp[i][(int) cnt.size()], choose(other, k - i)));
  }

  printf("%d\n", sol);

  return 0;
}
