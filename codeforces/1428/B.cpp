#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int t, n;
char s[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s);
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      a += s[i] == '<';
      b += s[i] == '>';
    }

    if (a == 0 || b == 0) {
      printf("%d\n", n);
      continue;
    }

    int sol = n;
    for (int i = 0; i < n; ++i) {
      int p = (i - 1 + n) % n;
      if (s[p] != '-' && s[i] != '-') --sol;
    }

    printf("%d\n", sol);
  }
  return 0;
}
