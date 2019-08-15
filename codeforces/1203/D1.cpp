#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int ns, nt;
char s[MAXN], t[MAXN];
int pref[MAXN], suff[MAXN];

int main(void) {
  scanf("%s%s", s, t);
  ns = strlen(s);
  nt = strlen(t);

  pref[0] = s[0] == t[0];
  for (int i = 1; i < ns; ++i) {
    pref[i] = pref[i - 1];
    if (pref[i] == nt) continue;
    if (s[i] == t[pref[i]]) ++pref[i];
  }

  suff[ns - 1] = s[ns - 1] == t[nt - 1];
  for (int i = ns - 2; i >= 0; --i) {
    suff[i] = suff[i + 1];
    if (suff[i] == nt) continue;
    if (s[i] == t[nt - suff[i] - 1]) ++suff[i];
  }

  //for (int i = 0; i < ns; ++i) printf("%d ", pref[i]); printf("\n");
  //for (int i = 0; i < ns; ++i) printf("%d ", suff[i]); printf("\n");

  //TRACE(pref[ns - 1]);

  assert(pref[ns - 1] == nt);
  assert(suff[0] == nt);

  int hi = 0, sol = 0;
  for (int lo = 0; lo < ns; ++lo) {
    while (hi < ns && pref[lo] + suff[hi] >= nt) ++hi;
    sol = max(sol, hi - lo - 2);
    if (pref[lo] == nt) sol = max(sol, ns - lo - 1);
    if (suff[lo] == nt) sol = max(sol, lo);
  }

  printf("%d\n", sol);
  return 0;
}
