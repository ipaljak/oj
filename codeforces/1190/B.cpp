#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int a[MAXN], b[MAXN];

map<int, int> cnt;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }

  sort(a, a + n);

  int cnt2 = 0;
  for (auto &p : cnt) {
    if (p.second > 2) { printf("cslnb\n"); return 0; }
    if (p.second == 2) {
      ++cnt2;
      if (cnt.find(p.first - 1) != cnt.end() || p.first == 0) {
        printf("cslnb\n");
        return 0;
      }
    }
  }

  if (cnt2 > 1) { printf("cslnb\n"); return 0; }

  b[0] = 0;
  for (int i = 1; i < n; ++i)
    b[i] = min(a[i], b[i - 1] + 1);

  bool x = false;
  for (int i = 0; i < n; ++i) {
    assert(b[i] <= a[i]);
    bool y = (a[i] - b[i]) % 2 == 1;
    x ^= y;
  }

  if (x)
    printf("sjfnb\n");
  else
    printf("cslnb\n");
  return 0;
}
