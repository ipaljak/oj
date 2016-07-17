#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
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

int q;

unordered_map<llint, llint> fee; 

inline void update(llint u, llint v, llint w) {
  while (u != v) {
    if (u < v) 
      swap(u, v);
    fee[u] += w; 
    u /= 2;
  }
}

inline llint dist(llint u, llint v) {
  llint ret = 0;
  while (u != v) {
    if (u < v) swap(u, v);
    ret += fee[u];
    u /= 2;
  }
  return ret;
}

int main(void) {

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    
    int t;
    llint u, v;
  
    scanf("%d%lld%lld", &t, &u, &v);

    if (t == 2) {
      printf("%lld\n", dist(u, v));
      continue; 
    }

    int w; scanf("%d", &w);
    update(u, v, (llint) w);
 
  }

  return 0;

}

