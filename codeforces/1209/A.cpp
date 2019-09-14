#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 101;

bool bio[MAXN];

int n;
int a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  sort(a, a + n);
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    if (bio[i]) continue;
    ++sol;
    for (int j = i; j < n; ++j) {
      if (bio[j]) continue;
      if (a[j] % a[i] == 0) bio[j] = true;
    }
  }

  printf("%d\n", sol);
  return 0;
}
