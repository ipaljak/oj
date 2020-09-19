#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int a[MAXN];

map<int, int> cnt;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sort(a, a + n);
  for (int i = 0; i < n; i += 2)
    if (i + 1 < n) swap(a[i], a[i + 1]);

  printf("%d\n", (n - 1) / 2);
  for (int i = 0; i < n; ++i) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
