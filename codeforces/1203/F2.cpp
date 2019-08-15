#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 110;

int n, r;
int memo[MAXN][60010];
vector<pair<int, int>> rise, fall;

inline bool cmp_rise(const pair<int, int> &A, const pair<int, int> &B) {
  return A.first < B.first;
}

inline bool cmp_fall(const pair<int, int> &A, const pair<int, int> &B) {
  return A.first + A.second > B.first + B.second;
}

inline void no() {
  printf("NO\n");
  exit(0);
}

int dp(int i, int r) {
  auto &ref = memo[i][r];
  if (ref != -1) return ref;
  if (i == (int) fall.size()) return ref = 0;
  int ret = dp(i + 1, r);
  if (r >= fall[i].first)
    ret = max(ret, 1 + dp(i + 1, r + fall[i].second));
  return ref = ret;
}

int main(void) {
  scanf("%d%d", &n, &r);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b >= 0) {
      rise.emplace_back(a, b);
    } else {
      fall.emplace_back(max(a, -b), b);
    }
  }

  sort(rise.begin(), rise.end(), cmp_rise);
  sort(fall.begin(), fall.end(), cmp_fall);

  int sol = 0;
  for (const auto &p : rise) {
    if (r < p.first) continue;
    ++sol;
    r += p.second;
  }

  memset(memo, -1, sizeof memo);
  printf("%d\n", sol + dp(0, r));

  return 0;
}
