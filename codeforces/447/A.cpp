#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 305;

bool bio[MAXN];

int p, n;

int main(void) {
  scanf("%d%d", &p, &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    x %= p;
    if (bio[x]) {
      printf("%d\n", i + 1);
      return 0;
    }
    bio[x] = true;
  }

  printf("-1\n");
  return 0;
}
