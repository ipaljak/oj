#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int n;
char s[3], t[3];

bool ok(const string &a) {
  for (int i = 1; i < 3 * n; ++i) {
    if (a[i - 1] == s[0] && a[i] == s[1]) return false;
    if (a[i - 1] == t[0] && a[i] == t[1]) return false;
  }
  return true;
}

void answer(const string &ans) {
  cout << "YES" << endl;
  cout << ans << endl;
  exit(0);
}

void check(vector<char> &v) {
  string A, B;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < n; ++j)
      A.push_back(v[i]);
  for (int i = 0; i < n; ++i) {
    B.push_back(v[0]);
    B.push_back(v[1]);
  }
  for (int i = 0; i < n; ++i) B.push_back(v[2]);
  if (ok(A)) answer(A);
  if (ok(B)) answer(B);
}

int main(void) {
  scanf("%d", &n);
  scanf("%s%s", s, t);

  vector<char> v{'a', 'b', 'c'};
  do {
    check(v);
  } while (next_permutation(v.begin(), v.end()));

  cout << "NO" << endl;

  return 0;
}
