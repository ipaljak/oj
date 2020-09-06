#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;

int t, n;
int a[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    llint sum = 0, sol = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += (llint) a[i];
      sol = max(sum, sol);
    }
    printf("%lld\n", sol);
  }
  return 0;
}
