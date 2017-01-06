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

const int MAXN = 101;

int n;
int a[MAXN];

int main(void) {

  scanf("%d", &n);

  int sum = 0;
  bool all_zero = true;

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    all_zero &= a[i] == 0;
  }

  if (all_zero) {
    printf("NO\n");
    return 0;
  }
    
  printf("YES\n");
  if (sum != 0) {
    printf("1\n1 %d\n", n);
  } else {
    int pivot = 0;
    for (; a[pivot] == 0; ++pivot);
    printf("2\n1 %d\n%d %d\n", pivot + 1, pivot + 2, n);
  }

  return 0;

}

