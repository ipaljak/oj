#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 26;

int n, m;
string s[MAXN], t[MAXN];

int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < m; ++i) cin >> t[i];
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << s[(x - 1) % n] + t[(x - 1) % m] << "\n";
  }
  return 0;
}
