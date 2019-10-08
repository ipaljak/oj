#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int n;
char s[MAXN];

int main(void) {
  scanf("%d", &n);
  scanf("%s", s);
  vector<int> v;
  int curr = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) { ++curr; continue; }
    v.push_back(curr);
    curr = 1;
  }
  v.push_back(curr);

  llint total = (llint) n * (n + 1) / 2;
  total -= (llint) n;
  for (int i = 1; i < v.size(); ++i)
    total -= (llint) (v[i - 1] + v[i] - 1);
  printf("%lld\n", total);
  return 0;
}
