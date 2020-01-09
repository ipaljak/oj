#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e3 + 10;

char s[MAXN];

int k, max_w, n;
int w[27];

int main(void) {
  scanf("%s", s); n = strlen(s);
  scanf("%d", &k);
  for (int i = 0; i < 26; ++i) {
    scanf("%d", &w[i]);
    max_w = max(max_w, w[i]);
  }

  llint sol = 0;
  for (int i = 0; i < n; ++i)
    sol += (llint) w[s[i] - 'a'] * (i + 1);
  for (int i = n; i < n + k; ++i)
    sol += (llint) max_w * (i + 1);

  printf("%lld\n", sol);
  return 0;
}
