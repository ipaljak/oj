#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int t, n;
char s[MAXN];

void solve() {
  scanf("%d", &n);
  scanf("%s", s);

  int a = 0, b = 0, curr = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) { ++curr; continue; }
    if (s[i - 1] == '0') a += curr - 1; else b += curr - 1;
    curr = 1;
  }
  if (s[n - 1] == '0') a += curr - 1; else b += curr - 1;

  printf("%d\n", max(a, b));
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
