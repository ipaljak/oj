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

int t; 

inline void solve() {
  int r, n; scanf("%d%d", &n, &r); --r;
  int sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    int x; scanf("%d", &x); --x;
    sum += x;
  }
  for (int i = 0; i < n; ++i) 
    if ((sum + i) % n == r)
      printf("%d\n", i + 1);
}

int main(void) {

  scanf("%d", &t);
  while (t --> 0)
    solve();

  return 0;

}

