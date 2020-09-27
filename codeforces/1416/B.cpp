#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e4 + 10;

struct Move {
  int i, j, x;
  Move() {}
  Move(int i, int j, int x) : i(i), j(j), x(x) {}
};

int t, n;
int a[MAXN];

vector<Move> sol;

void move(int i, int j, int x) {
  sol.emplace_back(i, j, x);
  a[i] -= x * (i + 1);
  a[j] += x * (i + 1);
}

void solve() {
  sol.clear();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  int s = 0;
  for (int i = 0; i < n; ++i) s += a[i];

  if (s % n != 0) {
    printf("-1\n");
    return;
  }

  s /= n;
  for (int i = 1; i < n; ++i) {
    assert(a[0] >= i);
    if (a[i] % (i + 1) != 0) {
      int add = (i + 1) - (a[i] % (i + 1));
      assert(add <= i);
      move(0, i, add);
    }
    int x = a[i] / (i + 1);
    //TRACE(a[0] _ a[i] _ i + 1 _ x);
    move(i, 0, x);
    //TRACE(a[i]);
    assert(a[i] == 0);
  }

  for (int i = 1; i < n; ++i) {
    assert(a[i] <= s);
    if (a[i] == s) continue;
    move(0, i, s - a[i]);
  }

  printf("%d\n", (int) sol.size());
  for (auto m : sol)
    printf("%d %d %d\n", m.i + 1, m.j + 1, m.x);
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
