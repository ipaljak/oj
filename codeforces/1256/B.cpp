#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 105;

bool bio[MAXN];

int q, n;
int a[MAXN];

void solve() {
  scanf("%d", &n); memset(bio, false, sizeof bio);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  int last = -1;
  while (last < n - 1) {
    int pivot = last + 1;
    for (int i = last + 2; i < n; ++i)
      if (a[i] < a[pivot]) pivot = i;
    //TRACE(pivot);
    for (int i = pivot; i > last + 1; --i)
      swap(a[i - 1], a[i]);
    if (last + 1 > 0 && a[last] > a[last + 1]) swap(a[last], a[last + 1]);
    last = pivot;
  }

  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
}

int main(void) {
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}
