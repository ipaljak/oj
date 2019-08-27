#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
char s[MAXN];

int main(void) {
  scanf("%s", s);
  n = strlen(s);

  stack<pair<char, int>> S;
  for (int i = 0; i < n; ++i) {
    if (S.empty() || s[i] == '1') {
      S.push({s[i], i});
      continue;
    }
    if (S.top().first == '1') {
      S.pop();
    } else {
      S.push({s[i], i});
    }
  }

  while (!S.empty()) {
    auto p = S.top(); S.pop();
    s[p.second] = '0';
  }

  printf("%s\n", s);
  return 0;
}
