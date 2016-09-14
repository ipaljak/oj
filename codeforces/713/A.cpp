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

const int MAXT = 100010;
const int MAXN = 1 << 18; 

int n; 
int cnt[2*MAXN];

map<string, int> mapa;

void bitify(llint x, int val) {

  string ret = "";
  
  for (int i = 0; i < 18; ++i) {
    if (x & 1) 
      ret += "1";
    else
      ret += "0";
    x /= 10;
  }

  reverse(ret.begin(), ret.end());
  mapa[ret] += val;

}

int main(void) {

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    
    char q[2]; scanf("%s", q);
    
    if (q[0] == '+') {
      llint x; scanf("%lld", &x);
      bitify(x, 1);
    }

    if (q[0] == '-') {
      llint x; scanf("%lld", &x);
      bitify(x, -1);
    }

    if (q[0] == '?') {

      char mask[20]; 
      scanf("%s", mask);

      int len = strlen(mask);
      string ret = "";

      for (int i = 0; i < 18 - len; ++i)
        ret += "0";

      for (int i = 0; i < len; ++i)
        ret += mask[i];

      printf("%d\n", mapa[ret]);

    }

  }

  return 0;

}

