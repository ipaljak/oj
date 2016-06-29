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

const int MAXN = 100010;

bool bicolorable = true; 

int n, m;
int bio[MAXN];

vector <int> v[MAXN];

void dfs(int node, int color) {

  bio[node] = color; 
  for (auto& next : v[node]) {
    if (bio[next] == color)
      bicolorable = false;
    if (bio[next] != -1) 
      continue;
    dfs(next, 1 - color); 
  }

}

int main(void) {

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b; scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  } 

  memset(bio, -1, sizeof bio);
  for (int i = 0; i < n; ++i) {
    if (bio[i] == -1) 
      dfs(i, 0);
  }

  if (!bicolorable) {
    printf("-1\n");
    return 0;
  }

  int a = 0, b = 0;
  for (int i = 0; i < n; ++i)
    if (bio[i] == 0) ++a; else ++b;

  assert(a + b == n);

  printf("%d\n", a);
  for (int i = 0; i < n; ++i)
    if (bio[i] == 0) 
      printf("%d ", i + 1);

  printf("\n%d\n", b);
  for (int i = 0; i < n; ++i)
    if (bio[i] == 1)
      printf("%d ", i + 1);

  printf("\n");
  return 0;

}

