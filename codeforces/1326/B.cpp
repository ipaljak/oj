#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int n;
int b[MAXN], a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  int mx = 0;
  a[0] = b[0];
  for (int i = 1; i < n; ++i) {
    mx = max(mx, a[i - 1]);
    a[i] = b[i] + mx;
  }

  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
