#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;

int n;
int h[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &h[i + 1]);

  int ret = 0, curr = 0;
  for (int i = 0; i < n; ++i) {
    curr += h[i] - h[i + 1];
    ret = min(ret, curr);
  }

  printf("%d\n", -ret);
  return 0;
}
