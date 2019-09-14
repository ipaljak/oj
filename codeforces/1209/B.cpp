#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 105;

int n;
int a[MAXN], b[MAXN];

char s[MAXN];

void flip(int x) {
  if (s[x] == '1') s[x] = '0'; else s[x] = '1';
}

int main(void) {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);

  int sol = 0;
  for (int i = 0; i < n; ++i) sol += s[i] == '1';
  for (int i = 1; i <= 50000; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >= b[j] && (i - b[j]) % a[j] == 0) flip(j);
    }
    int curr = 0;
    for (int j = 0; j < n; ++j) curr += s[j] == '1';
    sol = max(sol, curr);
  }

  printf("%d\n", sol);
  return 0;
}
