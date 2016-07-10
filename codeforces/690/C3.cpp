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

int n, u, v, d; 
int dad[20][MAXN], lvl[MAXN];

inline void add(int x, int p) {
  dad[0][x] = p;
  for (int i = 1; i < 20; ++i) {
    if (dad[i - 1][x] == -1)
      dad[i][x] = -1;
    else
      dad[i][x] = dad[i - 1][dad[i - 1][x]];
  }
  lvl[x] = lvl[p] + 1;
}

inline int dist(int a, int b) {

  int ret = 0;

  if (lvl[a] < lvl[b])
    swap(a, b);
  
  for (int i = 19; i >= 0; --i) 
    if (lvl[a] - (1 << i) >= lvl[b]) {
      a = dad[i][a];
      ret += 1 << i;
    }

  if (a == b) 
    return ret; 

  for (int i = 19; i >= 0; --i)
    if (dad[i][a] != dad[i][b]) {
      a = dad[i][a];
      b = dad[i][b];
      ret += 2 * (1 << i);
    }

  return ret + 2;

}

int main(void) {

  memset(dad, -1, sizeof dad);

  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    
    int x; scanf("%d", &x); --x;
    add(i, x);

    int dist_u = dist(i, u), dist_v = dist(i, v);

//    TRACE(u _ v _ dist_u _ dist_v);
    if (dist_u > d) {
      d = dist_u;
      v = i;
    } else if (dist_v > d) {
      d = dist_v;
      u = i;
    }

    printf("%d ", d);

  }

  printf("\n");

  return 0;

}

