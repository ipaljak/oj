#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

set<char> S;

int main(void) {
  char s[10], len = 0;
  while (true) {
    scanf("%s", s); len = strlen(s);
    if (s[2] == '}') {
      S.insert(s[1]);
      break;
    }
    if (s[1] == '}') {
      if (s[0] != '{') S.insert(s[0]);
      break;
    }
    if (s[0] == '{') S.insert(s[1]); else S.insert(s[0]);
  }

  printf("%d\n", (int) S.size());
  return 0;
}
