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
const int B1= 33941, MOD1 = 1e9 + 9;

const int MAXN = 100010;

int k;
llint a[MAXN];

inline int add(int a, int b) {
  a += b; 
  if (a < 0) a += MOD;
  return a % MOD;
}

inline int mul(int a, int b) {
  return (llint) a * b % MOD;
}

int pot(int b, llint e) {
  int ret = 1;
  while (e > 0) {
    if (e & 1) ret = mul(ret, b);
    e >>= 1; b = mul(b, b);
  }
  return ret;
}

int inv(int x) {
  return pot(x, MOD - 2); 
}

int main(void) {

  bool even = false; 

  scanf("%d", &k);
  for (int i = 0; i < k; ++i) { 
    scanf("%lld", &a[i]);
    even |= (a[i] & 1) == 0;
  }
  
  int q = 2; 
  for (int i = 0; i < k; ++i) 
    q = pot(q, a[i]);

  q = mul(q, inv(2));

  if (even) 
    printf("%d/%d\n", mul(add(q, 1), inv(3)), q);
  else
    printf("%d/%d\n", mul(add(q, -1), inv(3)), q);

  return 0;

}

