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

const int MAXN = 100010;
const llint INF = 1LL << 62;

int n;
int c[MAXN];

llint dp[3][MAXN];

string s[MAXN], rs[MAXN];

int main(void) {

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> c[i];

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    rs[i] = string(s[i].rbegin(), s[i].rend());
  }
 
  dp[0][0] = 0;
  dp[1][0] = c[0];
  
  for (int i = 1; i < n; ++i) {
    dp[0][i] = dp[1][i] = INF;
    if (s[i] >= s[i - 1]) dp[0][i] = min(dp[0][i], dp[0][i - 1]);
    if (s[i] >= rs[i - 1]) dp[0][i] = min(dp[0][i], dp[1][i - 1]);
    if (rs[i] >= s[i - 1]) dp[1][i] = min(dp[1][i], dp[0][i - 1] + c[i]);
    if (rs[i] >= rs[i - 1]) dp[1][i] = min(dp[1][i], dp[1][i - 1] + c[i]);
  }

  llint sol = min(dp[0][n - 1], dp[1][n - 1]);

  if (sol == INF)
    printf("-1\n");
  else
    printf("%lld\n", sol);

  return 0;

}

