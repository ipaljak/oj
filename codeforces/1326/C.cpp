#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;
const int MOD = 998244353;

int add(int a, int b) {
  if (a + b < 0) return a + b + MOD;
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

int n, k;
int p[MAXN], q[MAXN];

vector<int> v;

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]); --p[i];
    q[p[i]] = i;
  }

  llint tot = 0;
  for (int i = 0; i < k; ++i) {
    tot += (llint) (n - i);
    v.emplace_back(q[n - i - 1]);
  }

  sort(v.begin(), v.end());

  int ways = 1;
  for (int i = 1; i < v.size(); ++i) {
    int x = v[i] - v[i - 1];
    ways = mul(ways, x);
  }

  printf("%lld %d\n", tot, ways);

  return 0;
}
