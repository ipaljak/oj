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

char a[MAXN], b[MAXN];

int n;
int swp[27];

int main(void) {

  memset(swp, -1, sizeof swp);

  scanf("%s%s", a, b);
  n = strlen(a);

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (swp[a[i] - 'a'] != -1 && swp[a[i] - 'a'] != a[i] - 'a') ok = false;
      swp[a[i] - 'a'] = a[i] - 'a';
      continue;
    }
    if (swp[b[i] - 'a'] != a[i] - 'a' && swp[b[i] - 'a'] != -1) ok = false;
    if (swp[a[i] - 'a'] != b[i] - 'a' && swp[a[i] - 'a'] != -1) ok = false;
    swp[a[i] - 'a'] = b[i] - 'a';
    swp[b[i] - 'a'] = a[i] - 'a';
  } 

  if (!ok) {
    printf("-1\n");
    return 0;
  }

  int sol = 0;
  set <pair<char, char>> s;

  for (int i = 0; i < 26; ++i) {
    if (swp[i] == i || swp[i] == -1)
      continue;
    s.insert({min(i, swp[i]), max(i, swp[i])});
  }

  printf("%d\n", (int) s.size());
  for (set<pair<char,char>> :: iterator it = s.begin(); it != s.end(); ++it) {
    printf("%c %c\n", it -> first + 'a', it -> second + 'a');
  }

  return 0;

}

