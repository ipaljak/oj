#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
int a[MAXN];

inline void end(const char *s) {
  printf("%s\n", s);
  exit(0);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  if (n % 2 == 1) end("NO");

  sort(a, a + n);
  int curr = a[0], need = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == curr) {
      ++need;
    } else {
      if ((a[i] == curr + 1 && need <= 0) || a[i] > curr + 1) end("NO");
      need *= -1;
      curr = a[i];
      ++need;
    }
  }

  if (need != 0)
    end("NO");
  else
    end("YES");

  return 0;
}
