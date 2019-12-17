#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

char s[110];

int n;

void solve() {
  int len = strlen(s);
  int sum = 0;
  for (int i = 0; i < len; ++i)
    sum += s[i] - '0';

  if (sum % 3 != 0) {
    printf("cyan\n");
    return;
  }

  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      if (i == j) continue;
      if (((s[i] - '0') * 10 + s[j] - '0') % 4 == 0 && (s[j] == '0' || s[j] == '5')) {
        printf("red\n");
        return;
      }
    }
  }

  printf("cyan\n");
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    solve();
  }
  return 0;
}
