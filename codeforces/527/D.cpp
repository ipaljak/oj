#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
vector<pair<int, int>> v;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, w;
    scanf("%d%d", &x, &w);
    v.emplace_back(x - w, x + w);
  }

  sort(v.begin(), v.end(), [](const pair<int, int> &A, const pair<int, int> B) {
    return A.second < B.second;
  });

  int sol = 1;
  int lst = v[0].second;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].first >= lst) {
      ++sol;
      lst = v[i].second;
    }
  }

  printf("%d\n", sol);
  return 0;
}
