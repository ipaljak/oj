#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

bool bio[MAXN];

int n, q;
int a[MAXN], m[MAXN], cnt[MAXN];

set<int> s;

int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    m[a[i]] = i;
    cnt[a[i]]++;
  }

  int last = -1, mx = 0, sol = 0;
  for (int i = 0; i < n; ++i) {
    if (!bio[a[i]]) {
      s.insert(a[i]);
      mx = max(mx, cnt[a[i]]);
      bio[a[i]] = true;
    }
    if (m[a[i]] != i) continue;
    s.erase(s.find(a[i]));
    if (s.empty()) {
      sol += i - last - mx;
      last = i;
      mx = 0;
    }
    //TRACE(i _ mx);
  }

  printf("%d\n", sol);
  return 0;
}
