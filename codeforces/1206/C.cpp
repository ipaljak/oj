#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int a[2 * MAXN];

int main(void) {
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("NO\n");
    return 0;
  }

  printf("YES\n");
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    a[i] = 2 * i; a[i + n] = 2 * i + 1;
    if (i % 2 == 1) swap(a[i], a[i + n]);
  }

  for (int i = 0; i < 2 * n; ++i)
    printf("%d ", a[i] + 1);
  printf("\n");
  return 0;
}
