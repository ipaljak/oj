#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 998244353;
const int MAXN = 3e5 + 10;

int n, k;
int fact[MAXN];

vector<pair<int, int>> e;

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
      --b;
    }
    a = mul(a, a);
    b /= 2;
  }
  return ret;
}

int inv(int x) {
  return mypow(x, MOD - 2);
}

int choose(int n, int k) {
  return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

inline void init() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = mul(i, fact[i - 1]);
}

int main(void) {
  init();
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r); ++r;
    e.emplace_back(l, 1);
    e.emplace_back(r, -1);
  }

  sort(e.begin(), e.end());
  int cnt = 0, sol = 0;
  for (auto &p : e) {
    //TRACE(cnt _ sol);
    if (p.second == -1) {
      --cnt;
      continue;
    }
    ++cnt;
    if (cnt >= k) sol = add(sol, choose(cnt - 1, k - 1));
  }

  printf("%d\n", sol);
  return 0;
}
