#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MAXN = 105;

int t, n;
int a[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    if (n == 1) {
      printf("T\n");
      continue;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) sum += a[i];
    if (a[n - 1] * 2 > sum) {
      printf("T\n");
      continue;
    }
    if (sum % 2 == 1) printf("T\n"); else printf("HL\n");
  }
  return 0;
}
