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

const int MAXN = 105;

bool bio[MAXN];

int n;
int __next[MAXN], size[MAXN];

llint gcd(llint a, llint b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

llint lcm(llint a, llint b) {
  return a * b / gcd(a, b);
}

int main(void) {

  scanf("%d", &n); 
  for (int i = 0; i < n; ++i) {
    scanf("%d", &__next[i]);
    --__next[i];
  }

  if (n == 1) {
    printf("1\n");
    return 0;
  }

  bool possible = true;
  for (int i = 0; i < n; ++i) {
    memset(bio, false, sizeof bio);
    int curr = i;
    while (!bio[curr]) {
      bio[curr] = true;
      curr = __next[curr];
      ++size[i];
    }
    if (size[i] % 2 == 0) 
      size[i] /= 2;
    possible &= curr == i;
  }

  if (!possible) {
    printf("-1\n");
    return 0;
  }

  llint sol = lcm(size[0], size[1]);
  for (int i = 2; i < n; ++i)
    sol = lcm(sol, size[i]);

  printf("%lld\n", sol);

  return 0;

}

