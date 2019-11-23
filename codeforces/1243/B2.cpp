#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 55;

int k, n;

char s[MAXN], t[MAXN];

void solve() {
  scanf("%d", &n);
  scanf("%s%s", s, t);
  vector<pair<int, int>> sol;
  for (int i = 0; i < n; ++i) {
    if (s[i] == t[i]) continue;
    for (int j = i + 1; j < n; ++j) {
      if (t[j] == t[i]) {
        sol.emplace_back(i, j);
        swap(s[i], t[j]);
        break;
      }
      if (s[j] == t[i]) {
        sol.emplace_back(j, j);
        swap(s[j], t[j]);
        sol.emplace_back(i, j);
        swap(s[i], t[j]);
        break;
      }
    }
    if (s[i] != t[i]) {
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
  printf("%d\n", (int) sol.size());
  for (auto &p : sol)
    printf("%d %d\n", p.first + 1, p.second + 1);
}

int main(void) {
  scanf("%d", &k);
  while (k--) solve();
  return 0;
}
