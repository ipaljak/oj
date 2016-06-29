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

const int MAXN = 1000010;

bool dp[1 << 11];

int n, k;
int c[MAXN];

vector <pair<int, int>> fact; 

set <int> masks;

int main(void) {

  scanf("%d%d", &n, &k);

  if (k == 1) {
    printf("Yes\n");
    return 0;
  }
  
  for (int i = 2; i * i <= k; ++i) {
    int cnt = 0; 
    while (k % i == 0) {
      k /= i; ++cnt;
    }
    if (cnt > 0) 
      fact.emplace_back(i, cnt);
  }

  if (k > 1) 
    fact.emplace_back(k, 1);

  for (int i = 0; i < n; ++i) {
    
    scanf("%d", &c[i]);
    if (c[i] == 1) continue;

    int mask = 0;
    bool fail = false;

    for (auto& p : fact) {
        int cnt = 0;
        mask <<= 1;
        while (c[i] % p.first == 0) {
          c[i] /= p.first; ++cnt;
        }
        mask += cnt >= p.second;
    }
    masks.insert(mask);
  } 

//  for (auto e : masks)
//    printf("%d\n", e);

  int m = (int) fact.size(); 
  dp[0] = true; 

  int ans = 0;
  for (int mask : masks)
    ans |= mask; 

  if (ans == (1 << m) - 1)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;

}
