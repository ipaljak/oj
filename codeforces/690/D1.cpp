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

const int MAXN = 110;

int r, s;

char str[MAXN];

int main(void) {

  scanf("%d%d", &r, &s);
  for (int i = 0; i < r; ++i) 
    scanf("%s", str);

  int sol = 0;
  bool outside = true; 
  for (int i = 0; i < s; ++i) {
    if (str[i] == 'B' && outside) {
      ++sol; outside = false;
    } 
    if (str[i] == '.' && !outside) {
      outside = true;
    }
  }

  printf("%d\n", sol);
  return 0;

}

