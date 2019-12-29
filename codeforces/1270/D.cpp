#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int n, k;

vector<pair<int, int>> a;

pair<int, int> ask(int x) {
  printf("?");
  for (int i = 0; i <= k; ++i) {
    if (i == x) continue;
    printf(" %d", i + 1);
  }
  printf("\n"); fflush(stdout);
  int a, b;
  scanf("%d%d", &a, &b);
  return {b, a};
}

void ans(int x) {
  printf("! %d\n", x);
  fflush(stdout);
  exit(0);
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= k; ++i)
    a.emplace_back(ask(i));

  sort(a.begin(), a.end());

  int x = 0, y = 0;
  for (auto &p : a) {
    if (p == a[0]) { ++x; continue; }
    if (p == a[a.size() - 1]) { ++y; continue; }
    assert(false);
  }

  ans(y);

  return 0;
}
