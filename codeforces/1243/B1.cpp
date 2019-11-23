#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e4 + 10;

int T, n;

char s[MAXN], t[MAXN];

void solve() {
  scanf("%d", &n);
  scanf("%s%s", s, t);
  vector<int> diff;
  for (int i = 0; i < n; ++i)
    if (s[i] != t[i]) diff.push_back(i);

  if (diff.size() > 2 || diff.size() == 1) { printf("No\n"); return; }
  if (diff.size() == 0) { printf("Yes\n"); return; }

  if (s[diff[0]] == s[diff[1]] && t[diff[0]] == t[diff[1]])
    printf("Yes\n");
  else
    printf("No\n");
}

int main(void) {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
