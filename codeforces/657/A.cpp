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

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n, d, h;

int main(void) {

  scanf("%d%d%d", &n, &d, &h);

  if (d > 2 * h || d < h) {
    printf("-1\n");
    return 0;
  }

  if (h == 1) {
    if (d == 1 && n != 2) {
      printf("-1\n");
      return 0;
    }
    for (int i = 2; i <= n; ++i)
      printf("1 %d\n", i);
    return 0;
  }

  int curr = 2;
  for (int i = 0; i < h; ++i) {
    printf("%d %d\n", curr - 1, curr);
    ++curr;
  }
  
  int prev = 1;
  for (int i = 0; i < d - h; ++i) {
    printf("%d %d\n", prev, curr);
    prev = curr; ++curr;
  }

  while (curr <= n) 
    printf("2 %d\n", curr++);

  return 0;

}

