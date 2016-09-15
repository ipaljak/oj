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

const int MAXN = 1005;
const int LOG = 11; 

int r, s, q;
int a[MAXN][MAXN], largest[MAXN][MAXN], sparse[MAXN][MAXN][LOG][LOG];

int r1, s1, r2, s2;

inline int min3(int a, int b, int c) {
  return min(a, min(b, c));
}

inline int min4(int a, int b, int c, int d) {
  return min(a, min3(b, c, d));
}

inline int max3(int a, int b, int c) {
  return max(a, max(b, c));
}

inline int max4(int a, int b, int c, int d) {
  return max(a, max3(b, c, d));
}

inline void preprocess() {

  for (int i = 1; i <= r; ++i) 
    for (int j = 1; j <= s; ++j) 
      if (a[i][j])
        largest[i][j] = 1 + min3(largest[i - 1][j - 1], largest[i][j - 1], largest[i - 1][j]);

  for (int k = 0; k < 10; ++k) {
    for (int l = 0; l < 10; ++l) {
      for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= s; ++j) {
          if (i + (1 << k) > r + 1 || j + (1 << l) > s + 1) {
            continue;
          }
          if (k == 0 && l == 0) { 
            sparse[i][j][k][l] = largest[i][j];
            continue;
          }
          if (k != 0) 
            sparse[i][j][k][l] = max(sparse[i][j][k - 1][l], sparse[i + (1 << (k - 1))][j][k - 1][l]);
          else
            sparse[i][j][k][l] = max(sparse[i][j][k][l - 1], sparse[i][j + (1 << (l - 1))][k][l - 1]);
        }
      }     
    }
  }

}

int get_max(int r1, int s1, int r2, int s2) {
  
  int k = 1, l = 1;
  
  while (1 << k < r2 - r1 + 1) ++k;
  while (1 << l < s2 - s1 + 1) ++l;

  --k; --l;

  return max4(sparse[r1][s1][k][l], sparse[r2 - (1 << k) + 1][s1][k][l],
              sparse[r1][s2 - (1 << l) + 1][k][l], sparse[r2 - (1 << k) + 1][s2 - (1 << l) + 1][k][l]);

}

int binary(int lo, int hi) {
  hi = min3(hi, r2 - r1 + 1, s2 - s1 + 1); 
  while (lo < hi) {
    int mid = (lo + hi) / 2 + 1;
    if (get_max(r1 + mid - 1, s1 + mid - 1, r2, s2) >= mid) 
      lo = mid; 
    else
      hi = mid - 1;
  }
  return lo;
}

int main(void) {

  scanf("%d%d", &r, &s);
  for (int i = 1; i <= r; ++i) 
    for (int j = 1; j <= s; ++j)
      scanf("%d", &a[i][j]);

  preprocess();

//  for (int i = 0; i <= r; ++i) {
//    for (int j = 0; j <= s; ++j) {
//      printf("%d ", largest[i][j]);
//    }
//    printf("\n");
//  }
//  
//  printf("\n");
//
//  for (int i = 0; i <= r; ++i) {
//    for (int j = 0; j <= s; ++j) {
//      printf("%d ", sparse[i][j][2][2]);
//    }
//    printf("\n");
//  }
//
//  TRACE(sparse[4][4][2][2]);
//  TRACE(get_max(4, 4, 7, 10));
//
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d%d%d", &r1, &s1, &r2, &s2);    
    printf("%d\n", binary(0, 1000));
  }
  
  return 0;

}

