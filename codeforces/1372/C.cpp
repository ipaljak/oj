#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    bool sorted = true;
    bool one_move = true;
    int lo = 0, hi = n - 1;
    for (; lo < n && a[lo] == lo + 1; ++lo);
    for (; hi >= 0 && a[hi] == hi + 1; --hi);
    sorted = lo == n;
    for (int i = lo; i <= hi; ++i) {
      if (a[i] ==  i + 1) one_move = false;
    }
    if (sorted) {
      printf("0\n");
      continue;
    }
    if (one_move)
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
