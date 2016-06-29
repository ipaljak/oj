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

int n, d;

int main(void) {

  scanf("%d%d", &n, &d);
  
  int sol = 0, tmp = 0; 
  for (int i = 0; i < d; ++i) {
    char s[101];  scanf("%s", s);
    bool wins = false;
    for (int j = 0; j < n; ++j) 
      if (s[j] == '0') wins = true;
    if (wins) ++tmp; else tmp = 0;
    sol = max(sol, tmp);
  }

  printf("%d\n", sol);

  return 0;

}

