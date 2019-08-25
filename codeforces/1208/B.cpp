#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2010;

int n;
int a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int sol = n;
  set<int> pref;
  for (int i = 0; i < n; ++i) {
    set<int> suff;
    if (pref.find(a[i]) != pref.end()) break;
    pref.insert(a[i]);
    sol = min(sol, n - i - 1);
    for (int j = n - 1; j >= i; --j) {
      if (suff.find(a[j]) != suff.end() || pref.find(a[j]) != pref.end()) {
        sol = min(sol, j - i);
        break;
      }
      suff.insert(a[j]);
    }
  }

  pref.clear();
  for (int i = n - 1; i >= 0; --i) {
    if (pref.find(a[i]) != pref.end()) {
      sol = min(sol, i + 1);
      break;
    }
    pref.insert(a[i]);
  }

  printf("%d\n", sol);
  return 0;
}
