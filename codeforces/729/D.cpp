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

const int MAXN = 200010;

char grid[MAXN];

int n, a, b, k;

vector <pii> comp;
vector <int> sol;

int main(void) {
  
  scanf("%d%d%d%d", &n, &a, &b, &k); ++n;
  scanf("%s", grid);

  grid[n - 1] = '1';

  int last = 0;
  while (last < n && grid[last] == '1') ++last;

  int max_total = 0;
  for (int i = last + 1; i < n; ++i) {
    
    if (grid[i] != '1') 
      continue;

    int size = i - last;
    
    comp.emplace_back(last, size); 
    max_total += (size / b);

    while (i < n && grid[i] == '1') ++i;
    last = i; 

  }

//  for (auto &p : comp) {
//    printf("last _ min -> %d %d\n", p.fst, p.snd);  
//  } 

  for (auto &p : comp) {
   
    int start = p.fst, size = p.snd;

    if (size / b == 0) continue;  
    int num = max(1, a - (max_total - (size / b)));
    int _sb = size / b;
    num = min(num, a);
    
//    TRACE(start _ size _ num);

    while (size - num*b >= 0) {
      sol.push_back(start + b - 1);
      start += b;
      size -= b;
    }

    max_total -= _sb;

  }  

  printf("%d\n", (int) sol.size());
  for (auto x : sol)
    printf("%d ", x + 1);
  printf("\n");

  return 0;

}

