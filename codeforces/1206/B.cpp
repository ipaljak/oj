#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

bool zero;

int n, neg;
int a[MAXN];

llint sol;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      zero = true;
      ++sol;
      continue;
    }
    neg += a[i] < 0;
    sol += (llint) (abs(a[i]) - 1);
  }

  if (neg % 2 == 0 || zero)
    printf("%lld\n", sol);
  else
    printf("%lld\n", sol + 2);
  return 0;
}
