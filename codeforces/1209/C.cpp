#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int maxdig[11], color[MAXN];

int t;
int n;

char s[MAXN];

void init() {
  memset(maxdig, -1, sizeof maxdig);
  for (int i = 0; i < n; ++i) color[i] = 0;
}

void solve() {
  scanf("%d", &n);
  scanf("%s", s);
  init();
  for (int i = 0; i < n; ++i) maxdig[s[i] - '0'] = i;
  for (int i = 1; i <= 9; ++i) maxdig[i] = max(maxdig[i], maxdig[i - 1]);
  //for (int i = 0; i < 10; ++i) printf("%d ", maxdig[i]);
  //printf("\n");
  //return;
  int last = -1, bmin = 10;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' || (i > maxdig[s[i] - '0' - 1] && s[i] - '0' <= bmin)) {
      color[i] = 1;
      last = s[i] - '0';
    } else {
      color[i] = 2;
      bmin = min(bmin, s[i] - '0');
    }
  }
  //for (int i = 0; i < n; ++i) printf("%d ", color[i]);
  //printf("\n");
  //return;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (color[i] == 1) continue;
    if (s[i] - '0' >= last) {
      last = s[i] - '0';
    } else {
      ok = false;
    }
  }
  if (!ok) {
    printf("-\n");
  } else {
    for (int i = 0; i < n; ++i) printf("%d", color[i]);
    printf("\n");
  }
}

int main(void) {
  scanf("%d", &t);
  while (t --> 0) solve();
  return 0;
}
