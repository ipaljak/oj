#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1005;

int n, m, d;
int c[MAXN], sol[MAXN];

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

int main(void) {
  scanf("%d%d%d", &n, &m, &d);
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%d", &c[i]);
    sum += c[i];
  }

  if (ceil(n - sum, m + 1) > d - 1) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  int k = (n - sum) / (m + 1);
  for (int i = 0; i < m + 1; ++i) {
    int kk = k;
    if (i + 1 <= (n - sum) % (m + 1)) ++kk;
    for (int j = 0; j < kk; ++j) printf("0 ");
    if (i < m)
      for (int j = 0; j < c[i]; ++j) printf("%d ", i + 1);
  }
  printf("\n");

  return 0;
}
