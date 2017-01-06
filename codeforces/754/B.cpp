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

const int n = 4;

char grid[5][5];

int dr[] = {-1, -1, 0, 1};
int ds[] = {0, 1, 1, 1};

bool check(int r, int s) {
  return r >= 0 && r < 4 && s >= 0 && s < 4 && grid[r][s] == 'x';
}

bool win() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] != 'x')
        continue;
      for (int k = 0; k < 4; ++k) {
        if (check(i + dr[k], j + ds[k]) && check(i - dr[k], j - ds[k]))
          return true;
      }
    }
  }
  return false;
}

int main(void) {

  for (int i = 0; i < n; ++i) 
    scanf("%s", grid[i]);

  bool ok = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (grid[i][j] == '.') {
        grid[i][j] = 'x';
        ok |= win();
        grid[i][j] = '.';
      }
    }
  } 

  if (ok) 
    printf("YES\n");
  else
    printf("NO\n");

  return 0;

}

