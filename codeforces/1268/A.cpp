#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int n, k;
char s[MAXN], ss[MAXN];

bool equal() {
  for (int i = k; i < n; ++i)
    if (s[i] != s[i - k]) return false;
  return true;
}

int main(void) {
  scanf("%d%d", &n, &k);
  scanf("%s", s);

  if (equal()) {
    printf("%d\n", n);
    printf("%s\n", s);
    return 0;
  }

  for (int i = 0; i < k; ++i) ss[i] = s[i];
  for (int i = k; i < n; ++i) ss[i] = ss[i - k];

  if (strcmp(ss, s) >= 0) {
    printf("%d\n", n);
    printf("%s\n", ss);
    return 0;
  }

  bool nine = true;
  for (int i = 0; i < k; ++i)
    nine &= s[i] == '9';

  if (nine) {
    printf("%d\n", n + 1);
    for (int i = 0; i < n + 1; ++i)
      if (i % k == 0) printf("1"); else printf("0");
    printf("\n");
    return 0;
  }

  int nn = k - 1;
  for (int i = k - 1; i >= 0; --i) {
    if (s[i] != '9') { nn = i; break; }
  }

  s[nn]++;
  for (int i = nn + 1; i < k; ++i) s[i] = '0';
  for (int i = k; i < n; ++i) s[i] = s[i - k];

  printf("%d\n", n);
  printf("%s\n", s);
  return 0;
}
