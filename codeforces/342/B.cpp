#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXN 100010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int N, M, s, f;
int t[MAXN], l[MAXN], r[MAXN];

int main(void) {

  scanf("%d%d%d%d", &N, &M, &s, &f);
  for (int i = 0; i < M; ++i) 
    scanf("%d%d%d", &t[i], &l[i], &r[i]);

  int dir = 1;
  if (s > f) dir = -1;

  int tren = 1, i = 0;
  while (s != f) {
    while (i < M && t[i] < tren) ++i; 
    if (t[i] == tren && ((s >= l[i] && s <= r[i]) || (s + dir >= l[i] && s + dir <= r[i]))) {
        printf("X");
        ++tren;
        continue;
    }
    s += dir;
    if (dir == 1) printf("R"); else printf("L");
    ++tren; 
  }

  printf("\n");

  return 0;

}

