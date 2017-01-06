#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN = 2e5 + 10;

char s[MAXN];

int n;

int main(void) {

  scanf("%d", &n);
  scanf("%s", s);

  int sol = 0;
  char ver = -1, hor = -1;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R' || s[i] == 'L') {
      if (hor == s[i]) continue;
      if (hor == -1) {
        hor = s[i];
        continue;
      }
      ++sol;
      hor = s[i];
      ver = -1;
    } else {
      if (ver == s[i]) continue;
      if (ver == -1) {
        ver = s[i];
        continue;
      }
      ++sol;
      ver = s[i];
      hor = -1;
    }
  } 

  printf("%d\n", sol + 1);

  return 0;

}

