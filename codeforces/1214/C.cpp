#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
char s[MAXN];

void No() {
  printf("No\n");
  exit(0);
}

void Yes() {
  printf("Yes\n");
  exit(0);
}

int main(void) {
  scanf("%d", &n);
  scanf("%s", s);

  bool move = false;
  int pref = 0;
  for (int i = 0; i < n; ++i) {
    pref += (s[i] == '(') - (s[i] == ')');
    if (pref < 0) {
      if (move) No();
      assert(pref == -1);
      move = true;
      pref = 0;
    }
  }

  if ((!move && pref == 0) || (move && pref == 1)) Yes();
  No();

  return 0;
}
