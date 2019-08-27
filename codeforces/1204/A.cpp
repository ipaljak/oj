#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 105;

char s[MAXN];

int main(void) {
  scanf("%s", s);
  int n = strlen(s);
  bool all_zero = true;
  for (int i = 1; i < n ; ++i) all_zero &= s[i] == '0';
  int sol = n / 2 + (n % 2);
  if (n % 2 == 1 && all_zero) --sol;
  printf("%d\n", sol);
  return 0;
}
