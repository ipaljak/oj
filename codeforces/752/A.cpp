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

int r, s, k;

int main(void) {

  scanf("%d%d%d", &r, &s, &k);

  bool left = k % 2; 

  if (k % 2 == 0) --k;
  k /= 2;

  char c = 'R';
  if (left)
    c = 'L';

  printf("%d %d %c\n", (k / s) + 1, (k % s) + 1, c);

  return 0;

}

