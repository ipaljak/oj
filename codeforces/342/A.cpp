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

int n, a, b, c;
int cnt[8];

int main(void) {

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    ++cnt[x]; 
  }

  c = cnt[3];
  cnt[3] -= c; cnt[1] -= c; cnt[6] -= c;

  b = cnt[6];
  cnt[1] -= b; cnt[2] -= b; cnt[6] -= b;

  a = cnt[4];
  cnt[1] -= a; cnt[2] -= a; cnt[4] -= a;

  bool ok = a >= 0 && b >= 0 && c >= 0;
  for (int i = 0; i < 8; ++i)
    ok &= cnt[i] == 0;

  if (!ok) {
    printf("-1\n");
    return 0;
  }

  for (int i = 0; i < a; ++i) printf("1 2 4\n");
  for (int i = 0; i < b; ++i) printf("1 2 6\n");
  for (int i = 0; i < c; ++i) printf("1 3 6\n");

  return 0;

}

