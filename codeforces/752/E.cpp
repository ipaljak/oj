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

const int MAXN = 1e6 + 10;
const int MAXT = 1e7 + 10;

int n, k; 
int a[MAXN], dp[MAXT];

llint sum = 0;

bool check(int x) { 
  for (int i = 0; i < x; ++i)
    dp[i] = 0;
  dp[x] = 1;
  for (int i = x + 1; i <= (int) 1e7; ++i)
    dp[i] = max(1, dp[i / 2] + dp[(i + (i % 2)) / 2]);
  llint _k = 0;
  for (int i = 0; i < n; ++i) 
    _k += (llint) dp[a[i]];
  return _k >= (llint) k;
}

int binary() {

  int lo = 0, hi = 1e7 + 10;
  while (lo < hi) {
    int mid = (lo + hi) / 2 + 1;
    if (check(mid)) 
      lo = mid;
    else
      hi = mid - 1;
  }
    
  return lo;

}

int main(void) {

  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  int sol = binary();

  if (!sol)
    printf("-1\n");
  else
    printf("%d\n", sol);

  return 0;

}

