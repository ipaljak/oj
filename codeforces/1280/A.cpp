#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

int t, x;
char s[MAXN];

vector<int> v;

inline int add(int a, int b) {
  if (a + b < 0) return a + b + MOD;
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

void solve() {
  scanf("%d", &x);
  scanf("%s", s);

  v.clear();
  int len = strlen(s);

  for (int i = 0; i < len; ++i)
    v.emplace_back(s[i] - '0');

  int l = 1;
  while (l <= x) {
    assert(l - 1 < v.size());
    len = add(len, mul(v[l - 1] - 1, add(len, -l)));
    int vs = v.size();
    if (v[l - 1] >= 2) {
      for (int i = l; i < vs && v.size() < x + 5; ++i)
        v.push_back(v[i]);
      if (v[l - 1] == 3) {
        for (int i = l; i < vs && v.size() < x + 5; ++i)
          v.push_back(v[i]);
      }
    }
    //TRACE(l _ len);
    //for (int x : v)
      //printf("%d ", x);
    //printf("\n");
    ++l;
  }

  printf("%d\n", len);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
