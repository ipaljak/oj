#include <bits/stdc++.h>

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

using namespace std;

typedef long long llint;

const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, c, a, b;
int ch[55][55];

pair<int, int> memo[55][55][205];

int add(int a, int b) {
  if (a + b < 0) return a + b + MOD;
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

inline void init() {
  for (int i = 0; i <= 50; ++i) ch[i][0] = ch[i][i] = 1;

  for (int i = 1; i <= 50; ++i)
    for (int j = 1; j < i; ++j)
      ch[i][j] = add(ch[i - 1][j - 1], ch[i - 1][j]);
}

pair<int, int> dp(int i, int j, int k) {
  //TRACE(i _ j _ k);
  if (memo[i][j][k].first != -1) return memo[i][j][k];
  if (k > 200) return memo[i][j][k] = {INF, 0};
  if (i == a && j == b && k % 2 == 1) return memo[i][j][k] = {k, 1};

  pair<int, int> ret = {INF, 0};
  for (int ii = 0; ii <= i; ++ii) {
    if (ii * 50 > c) break;
    for (int jj = 0; jj <= j; ++jj) {
      if (ii == 0 && jj == 0) continue;
      if (ii * 50 + jj * 100 > c) break;
      auto p = dp((a - i) + ii, (b - j) + jj, k + 1);
      p.second = mul(p.second, mul(ch[i][ii], ch[j][jj]));
      if (p.first == ret.first) ret.second = add(ret.second, p.second);
      if (p.first < ret.first) ret = p;
    }
  }

  return memo[i][j][k] = ret;
}


int main(void) {
  init();
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a += x == 50;
    b += x == 100;
  }

  memset(memo, -1, sizeof memo);

  auto sol = dp(a, b, 0);
  if (sol.first == INF) sol.first = -1;
  printf("%d\n%d\n", sol.first, sol.second);

  return 0;
}
