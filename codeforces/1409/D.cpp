#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t;

int sum(llint x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main(void) {
  scanf("%d", &t);
  while (t--) {
    char str[20];
    llint n = 0;
    int s, len;
    scanf("%s%d", str, &s);
    len = strlen(str);
    for (int i = 0; i < len; ++i) { n *= (llint) 10; n += (llint) (str[i] - '0'); }
    if (sum(n) <= s) {
      printf("0\n");
      continue;
    }
    if (sum(n + 1) == 1) {
      printf("1\n");
      continue;
    }

    llint sol = 1e18 + 10;
    llint x = 0;
    for (int i = 0; i < len; ++i) {
      x *= (llint) 10; x += (llint) (str[i] - '0');
      x += 1LL;
      for (int j = i + 1; j < len; ++j) x *= (llint) 10;
      assert(x >= n);
      if (sum(x) <= s) sol = min(sol, x - n);
      for (int j = i + 1; j < len; ++j) x /= (llint) 10;
      --x;
    }

    x = 1;
    for (int i = 0; i < len; ++i) x *= (llint) 10;
    if (sum(x) <= s) sol = min(sol, x - n);

    printf("%lld\n", sol);
  }
  return 0;
}
