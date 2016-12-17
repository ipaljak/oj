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

const int MAXN = 1010;
const int INF  = 2e9;

int n;
int ans[MAXN];

vector <int> sol;

inline void init() {
  for (int i = 0; i < n; ++i)
    sol.push_back(INF);
}

void print(vector <int> &v, bool pr_size) {
  if (pr_size) 
    printf("%d\n", (int) v.size());
  else
    printf("-1\n");
  for (int x : v)
    printf("%d ", x);
  printf("\n");
  fflush(stdout);
}

int main(void) {

  scanf("%d", &n);
  init();
  
  int p = 1; 
  for (; p <= n; p *= 2) {
    
    vector <int> a;
    vector <int> b;

    bool prev_a = false;
    int curr = 1;
  
    while (curr <= n) {
      for (int i = 0; i < p && curr <= n; ++i) {
        if (prev_a)
          b.push_back(curr);
        else
          a.push_back(curr);
        ++curr;
      } 
      prev_a = !prev_a;
    }

    if (!a.empty()) {
      print(a, true);
      for (int i = 0; i < n; ++i)
        scanf("%d", &ans[i]);

      for (int x : b)
        sol[x - 1] = min(sol[x - 1], ans[x - 1]);
    } 

    if (!b.empty()) {
      print(b, true);
      for (int i = 0; i < n; ++i)
        scanf("%d", &ans[i]);

      for (int x : a)
        sol[x - 1] = min(sol[x - 1], ans[x - 1]);
    }

  }

  print(sol, false);  

  return 0;

}
