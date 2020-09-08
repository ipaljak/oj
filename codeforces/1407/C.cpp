#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e4 + 10;

int n;
int sol[MAXN];

int ask(int x, int y) {
  printf("? %d %d\n", x + 1, y + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

void ans() {
  printf("! ");
  for (int i = 0; i < n; ++i) printf("%d ", sol[i]);
  printf("\n");
  exit(0);
}

int main(void) {
  scanf("%d", &n);
  int x = 0;
  for (int i = 1; i < n; ++i) {
    int A = ask(x, i), B = ask(i, x);
    assert(A != B);
    if (A > B) {
      sol[x] = A;
      x = i;
    } else {
      sol[i] = B;
    }
  }

  llint s = (llint) n * (n + 1) / 2;
  for (int i = 0; i < n; ++i)
    s -= (llint) sol[i];
  sol[x] = s;

  ans();
  return 0;
}
