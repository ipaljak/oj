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

const int MAXN = 500010;
const int MAXK = 200010;

const int mod = 1000003;

int n, k;
int fact[MAXN + MAXK];

inline int add(int a, int b) {
  return (a + b + mod) % mod;  
}

inline int mul(int a, int b) {
  return (llint) a * b % mod; 
}

inline int exp(int b, int e) {
  int ret = 1;
  while (e > 0) {
    if (e & 1) ret = mul(ret, b);
    e >>= 1; b = mul(b, b);
  }
  return ret;
}

inline int mod_inv(int x) {
  return exp(x, mod - 2); 
}

inline void init() {
  fact[0] = 1;
  for (int i = 1; i <= 700000; ++i) 
    fact[i] = mul(i, fact[i - 1]);
}

inline int choose(int x, int y) {
  return mul(fact[x], mod_inv(mul(fact[y], fact[x - y])));
}

int main(void) {

  init();
  
  scanf("%d%d", &n, &k);

  int sol = 0; 
  for (int i = 1; i <= n; ++i)  
    sol = add(sol, choose(i + k - 1, k - 1));

  printf("%d\n", sol);

  return 0;

}

