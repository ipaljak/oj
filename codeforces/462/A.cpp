#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 105;

int dr[] = {0, 1, 0, -1};
int ds[] = {1, 0, -1, 0};

char m[MAXN][MAXN];

int n;

inline bool inside(int r, int s) {
  return r >= 0 && s >= 0 && r < n && s < n;
}

bool check(int r, int s) {
  int cnt = 0;
  for (int i = 0; i < 4; ++i) {
    int _r = r + dr[i], _s = s + ds[i];
    cnt += inside(_r, _s) && m[_r][_s] == 'o';
  }
  return (cnt % 2) == 0;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%s", m[i]);

  bool ok = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      ok &= check(i, j);

  if (ok) printf("YES\n"); else printf("NO\n");

  return 0;
}
