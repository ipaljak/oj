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

const int MAXN = 200010;

int n;
int pos[MAXN];

char s[MAXN];

int main(void) {

  scanf("%d", &n);
  scanf("%s", s);;

  for (int i = 0; i < n; ++i)
    scanf("%d", &pos[i]);

  int sol = MOD;
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'L' && s[i - 1] == 'R') 
      sol = min(sol, (pos[i] - pos[i - 1]) / 2); 
  }

  if (sol == MOD)
    printf("-1\n");
  else
    printf("%d\n", sol);

  return 0;

}

