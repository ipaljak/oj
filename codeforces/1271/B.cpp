#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 202;

int n;
char s[MAXN];

void solve(char c) {
  char ss[MAXN];
  vector<int> sol;
  for (int i = 0; i < n; ++i) ss[i] = s[i];
  for (int i = 0; i < n - 1; ++i) {
    if (ss[i] == c) continue;
    sol.emplace_back(i + 1);
    if (ss[i] == 'B') ss[i] = 'W'; else ss[i] = 'B';
    if (ss[i + 1] == 'B') ss[i + 1] = 'W'; else ss[i + 1] = 'B';
  }
  if (ss[n - 1] != c) return;
  printf("%d\n", (int) sol.size());
  for (auto x : sol) printf("%d ", x);
  printf("\n");
  exit(0);
}

int main(void) {
  scanf("%d", &n);
  scanf("%s", s);

  solve('B');
  solve('W');

  printf("-1\n");
  return 0;
}
