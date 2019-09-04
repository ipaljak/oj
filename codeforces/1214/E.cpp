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
vector<int> chain;

bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
  return A.first > B.first;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    v.emplace_back(x, i + 1);
  }

  sort(v.begin(), v.end(), cmp);
  for (const auto &p : v)
    chain.emplace_back(2 * p.second - 1);

  for (int i = 1; i < chain.size(); ++i)
    printf("%d %d\n", chain[i - 1], chain[i]);

  int i = 0;
  for (const auto &p : v) {
    int d = p.first, node = 2 * p.second;
    int j = i + d - 1;
    assert(j < (int) chain.size());
    printf("%d %d\n", chain[j], node);
    if (j == (int) chain.size() - 1) chain.emplace_back(node);
    ++i;
  }

  return 0;
}
