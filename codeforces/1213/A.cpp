#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 101;

int n, A, B;
int a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    A += abs(x) % 2 == 0;
    B += abs(x) % 2 == 1;
  }
  printf("%d\n", min(A, B));

  return 0;
}
