#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1010;

int n, x, pos, a, b;
int c[MAXN][MAXN], f[MAXN];

int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

void bs() {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (mid <= pos) {
      a += (mid < pos);
      lo = mid + 1;
    } else {
      b++;
      hi = mid;
    }
  }
}

inline void init() {
  c[0][0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
  }

  f[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    f[i] = mul(i, f[i - 1]);
}

int main(void) {
  init();
  scanf("%d%d%d", &n, &x, &pos);
  bs();

  //TRACE(a _ b);

  if (a > pos || a >= x || b > (n - pos - 1) || b > (n - x)) {
    printf("0\n");
    return 0;
  }

  int ca = c[x - 1][a];
  int cb = c[n - x][b];
  printf("%d\n", mul(f[a], mul(f[b], (mul(ca, mul(cb, f[n - a - b - 1]))))));

  return 0;
}
