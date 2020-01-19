#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 110;

int n;
char s[MAXN];

set<char> ss;

int main(void) {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (c >= 'A' && c <= 'Z')
      ss.insert('a' + (c - 'A'));
    else
      ss.insert(c);
  }

  if ((int) ss.size() == 26)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
