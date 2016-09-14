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

const int MAXN = 3005; 

int n;
int a[MAXN], b[MAXN];

llint memo[MAXN][MAXN];

llint dp(int curr, int prev) {

  llint ret = 0LL;

  if (memo[curr][prev] != -1) 
    return memo[curr][prev];

  if (curr == n)
    return memo[curr][prev] = 0LL;

  ret = (llint) abs(a[curr] - b[prev]) + dp(curr + 1, prev);

  if (prev < n - 1) 
    ret = min(ret, dp(curr, prev + 1));

  return memo[curr][prev] = ret;

}

int main(void) {

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] -= i; 
    b[i] = a[i];
  }

  sort(b, b + n);

  memset(memo, -1, sizeof memo);
  printf("%lld\n", dp(0, 0));

  return 0;

}

