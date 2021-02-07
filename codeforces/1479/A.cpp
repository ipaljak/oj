#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int n;

int ask(int i) {
  if (i < 0 || i >= n) return 2 * n;
  printf("? %d\n", i + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

int main(void) {
  scanf("%d", &n);

  int lo = 0, hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2 + 1;
    if (ask(mid - 1) > ask(mid)) lo = mid; else hi = mid - 1;
  }

  printf("! %d\n", lo + 1);
  fflush(stdout);
  return 0;
}
