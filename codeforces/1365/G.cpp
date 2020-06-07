#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1001;

int n;
int msk[MAXN];

llint res[13];

llint ask(const vector<int> &v) {
  if (v.empty()) return 0;
  printf("? %d ", (int) v.size());
  for (int x : v) printf("%d ", x + 1);
  printf("\n"); fflush(stdout);
  llint ret;
  scanf("%lld", &ret);
  return ret;
}

void ans(const vector<llint> &v) {
  printf("! ");
  for (llint x : v) printf("%lld ", x);
  printf("\n"); fflush(stdout);
  exit(0);
}

int main(void) {
  scanf("%d", &n);

  vector<int> v[14];
  int i = 0;
  for (int mask = 0; mask < 1 << 13 && i < n; ++mask) {
    if (__builtin_popcount(mask) != 6) continue;
    for (int j = 0; j < 13; ++j)
      if (mask & (1 << j))
        v[j].emplace_back(i);
    msk[i] = mask;
    i++;
  }

  for (int i = 0; i < 13; ++i) res[i] = ask(v[i]);

  vector<llint> sol;
  for (int i = 0; i < n; ++i) {
    llint x = 0;
    for (int j = 0; j < 13; ++j) {
      if (msk[i] & (1 << j)) continue;
      x |= res[j];
    }
    sol.push_back(x);
  }

  ans(sol);
  return 0;
}
