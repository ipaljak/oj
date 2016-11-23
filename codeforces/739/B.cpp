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

const int MAXN = 200010;
const int LOGN = 18;

int n;
int a[MAXN], parent[20][MAXN], add[MAXN], sol[MAXN];

llint dist[20][MAXN];

vector <int> v[MAXN];

inline void precompute() {
  for (int i = 1; i < 20; ++i) { 
    parent[i][0] = -1;
    dist[i][0] = -1;
    for (int j = 0; j < n; ++j) {
      if (parent[i - 1][j] == -1) {
        parent[i][j] = -1;
        dist[i][j] = -1;
      } else {
        parent[i][j] = parent[i - 1][parent[i - 1][j]];
        dist[i][j] = dist[i - 1][parent[i - 1][j]] + dist[i - 1][j];
      }
    }
  }
}

inline int calc_add(int node) {
  int _node = node;
  for (int i = 19; i >= 0; --i) {
    if (parent[i][node] != -1 && dist[i][node] <= (llint) a[_node]) {
      a[_node] -= dist[i][node];
      node = parent[i][node];
    }
  } 
  return parent[0][node];
}

void dfs(int node) {
  sol[node] = 1;
  for (auto next : v[node]) {
    dfs(next);
    sol[node] += sol[next];
  }
  sol[node] -= add[node];
}

int main(void) {

  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%lld", &parent[0][i + 1], &dist[0][i + 1]);
    --parent[0][i + 1];
    v[parent[0][i + 1]].push_back(i + 1);
  }

  parent[0][0] = dist[0][0] = -1;

  precompute();

  for (int i = 0; i < n; ++i) {
    int add_node = calc_add(i);
    if (add_node > -1)
      ++add[add_node];
  }

  dfs(0);

  for (int i = 0; i < n; ++i)
    printf("%d ", sol[i] - 1);

  printf("\n");

  return 0;

}

