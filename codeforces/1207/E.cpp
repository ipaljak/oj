#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int ask(set<int> &s) {
  printf("?");
  for (llint x : s) printf(" %d", x);
  printf("\n");
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

void ans(int x) {
  printf("! %d\n", x);
  fflush(stdout);
  exit(0);
}

int main(void) {
  set<int> a, b;
  for (int i = 0; i < 100; ++i) a.insert(i + 1);
  for (int i = 0; i < 100; ++i)
    b.insert((i + 1) * (1 << 7));

  int A = ask(a);
  int B = ask(b);

  for (int aa : a)
    for (int bb : b)
      if ((aa ^ bb) == (A ^ B) && (A ^ aa) == (B ^ bb))
        ans(A ^ aa);

  assert(false);
  return 0;
}
