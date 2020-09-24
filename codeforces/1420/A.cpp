#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e4 + 10;

int t, n;
int a[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    bool ok = false;
    for (int i = 1; i < n; ++i)
      ok |= a[i] >= a[i - 1];
    if (ok) printf("YES\n"); else printf("NO\n");
  }
  return 0;
}
