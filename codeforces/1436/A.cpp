#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 150;

int t;
int a[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int s = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      s += a[i];
    }
    if (s == m) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
