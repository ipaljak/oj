#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

char s[105];
int n;

int main(void) {
  scanf("%d", &n);
  scanf("%s", s);
  int cnt8 = 0;
  for (int i = 0; i < n; ++i) cnt8 += s[i] == '8';

  int sol = 0;
  for (int i = 1; i <= 100; ++i)
    if (cnt8 >= i && i * 11 <= n) sol = i;

  printf("%d\n", sol);
  return 0;
}
