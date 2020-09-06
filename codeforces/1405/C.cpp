#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int t, n, k;
char s[MAXN];

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);

  bool ok = true;
  for (int i = 0; i < k; ++i) {
    bool one = false, zero = false;
    for (int j = i; j < n; j += k) {
      one |= s[j] == '1';
      zero |= s[j] == '0';
    }
    if (one && zero) ok = false;
    for (int j = i; j < n; j += k) {
      if (s[j] == '?') {
        if (one) s[j] = '1';
        if (zero) s[j] = '0';
      }
    }
  }

  int one = 0, zero = 0;
  for (int i = 0; i < k; ++i) {
    one += s[i] == '1';
    zero += s[i] == '0';
  }

  if (2 * max(one, zero) > k) ok = false;
  if (ok) printf("YES\n"); else printf("NO\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
