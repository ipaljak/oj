#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int a[3];

int main(void) {
  for (int i = 0; i < 3; ++i)
    scanf("%d", &a[i]);

  int ret = a[0] + a[1] + a[2];
  ret = max(ret, a[0] * a[1] * a[2]);
  ret = max(ret, (a[0] + a[1]) * a[2]);
  ret = max(ret, a[0] * (a[1] + a[2]));

  printf("%d\n", ret);
  return 0;
}
