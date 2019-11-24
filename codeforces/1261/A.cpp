#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2001;

int t, n, k;
char s[MAXN], target[MAXN];

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int ptr = 0;
  for (int i = 0; i < k - 1; ++i) {
    target[ptr++] = '(';
    target[ptr++] = ')';
  }
  for (int i = 0; i < (n / 2 - (k - 1)); ++i)
    target[ptr++] = '(';
  for (int i = 0; i < (n / 2 - (k - 1)); ++i)
    target[ptr++] = ')';
  //for (int i = 0; i < n; ++i)
    //printf("%c", target[i]);
  //printf("\n");
  
  vector<pair<int, int>> sol;
  for (int i = 0; i < n; ++i) {
    if (s[i] == target[i]) continue;
    int j = i + 1;
    for (; j < n; ++j)
      if (s[j] == target[i]) break;
    assert(s[j] == target[i]);
    sol.emplace_back(i, j);
    swap(s[i], s[j]);
  }

  printf("%d\n", (int) sol.size());
  for (auto &p : sol) printf("%d %d\n", p.first + 1, p.second + 1);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
