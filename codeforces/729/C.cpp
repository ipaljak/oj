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

int n, k, s, t;
int g[MAXN];

vector <pii> cars;

bool check(int v) {
  llint _t = 0;
  for (int i = 1; i < k; ++i) {
    int dist = g[i] - g[i - 1];
    int A = min(dist, v - dist), B = dist - A; 
    if (A < 0 || B < 0) 
      return false; 
    _t += (llint) A + (llint) 2*B;
  }
  return _t <= t; 
}

int binary(int lo, int hi) {
  while (lo < hi) {
    llint mid = ((llint)lo + hi) / 2;
    if (check((int) mid)) hi = mid; else lo = mid + 1; 
  }
  return lo;
} 

int main(void) {

  scanf("%d%d%d%d", &n, &k, &s, &t);

  for (int i = 0; i < n; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    cars.emplace_back(x, y);
  }

  g[0] = 0, g[1] = s;
  for (int i = 0; i < k; ++i) 
    scanf("%d", &g[i + 2]);
 
  k += 2;

  sort(g, g + k); 

  int v = binary(0, 2 * 1e9);
  int sol = (int) 1e9 * 2;

  for (auto &c : cars) {
    if (c.second >= v) 
      sol = min(sol, c.first);
  }

  if (sol == (int) 1e9 * 2)
    printf("-1\n");
  else
    printf("%d\n", sol);

  return 0;

}

