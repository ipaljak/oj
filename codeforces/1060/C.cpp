#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2020;
const int INF = 2e9 + 10;

int n, m, k;
int a[MAXN], b[MAXN], min_a[MAXN], min_b[MAXN];

void precompute(int size, int *x, int *min_x) {
  for (int i = 1; i <= size; ++i) min_x[i] = INF;
  for (int i = 0; i < size; ++i) {
    int sum = 0;
    for (int j = i; j < size; ++j) {
      sum += x[j];
      min_x[j - i + 1] = min(min_x[j - i + 1], sum);
    }
  }
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int j = 0; j < m; ++j) scanf("%d", &b[j]);
  scanf("%d", &k);

  precompute(n, a, min_a);
  precompute(m, b, min_b);

  //for (int i = 1; i <= n; ++i) printf("%d ", min_a[i]); printf("\n");
  //for (int i = 1; i <= m; ++i) printf("%d ", min_b[i]); printf("\n");

  int sol = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if ((llint) min_a[i] * min_b[j] <= (llint) k)
        sol = max(sol, i * j);

  printf("%d\n", sol);
  return 0;
}
