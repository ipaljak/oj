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

int N;

unordered_map <int, int> mx, my;
map <pii, int> m;

int main(void) {

  scanf("%d", &N);
  
  llint sol = 0;
  for (int i = 0; i < N; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    ++mx[x]; ++my[y]; ++m[{x, y}]; 
  }

  for (const auto &p : mx) 
    sol += (llint) p.snd * (p.snd - 1) / 2;

  for (const auto &p : my)
    sol += (llint) p.snd * (p.snd - 1) / 2;

  for (const auto &p : m)
    sol -= (llint) p.snd * (p.snd - 1) / 2;

  printf("%lld\n", sol);

  return 0;

}

