#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

char s[MAXN], t[MAXN];

int n;
map<pair<char, char>, int> m;

int main(void) {
  scanf("%d", &n);
  scanf("%s%s", s, t);

  int diff = 0;
  for (int i = 0; i < n; ++i) {
    m[{s[i], t[i]}] = i;
    diff += s[i] != t[i];
  }

  int sol = diff, ii = -1, jj = -1;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (m.find({'a' + i, 'a' + j}) == m.end()) continue;
      for (int k = 0; k < 26; ++k) {
        if (m.find({'a' + j, 'a' + k}) == m.end()) continue;
        if (i == j || j == k) continue;
        if (diff - (i == k) - 1 < sol) {
          sol = diff - (i == k) - 1;
          ii = m[{'a' + i, 'a' + j}] + 1;
          jj = m[{'a' + j, 'a' + k}] + 1;
        }
      }
    }
  }

  printf("%d\n%d %d\n", sol, ii, jj);
  return 0;
}
