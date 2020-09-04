#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int x = abs(a - b);
    printf("%d\n", ceil(x, 10));
  }
  return 0;
}
