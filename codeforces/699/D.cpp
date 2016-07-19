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

int bio[MAXN];

int n, c, t;
int dad[MAXN];

vector <int> v[MAXN];

void tree_dfs(int node) {
  bio[node] = t;
  for (int next : v[node]) 
    if (dad[next] == node)
      tree_dfs(next);
}

void find_cycle(int node) {
  bio[node] = t; 
  for (int next : v[node]) {
    if (bio[next] == t) {
      c = next; 
    } else {
      find_cycle(next);
    }
  }
}

int main(void) {

  t = 1;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &dad[i]); --dad[i];
    if (dad[i] == i) continue;
    v[dad[i]].push_back(i);
  }

  int root = -1, sol = 0;
  for (int i = 0; i < n; ++i) {
    ++t;
    if (dad[i] == i) {
      tree_dfs(i);
      if (root == -1) {
        root = i;
      } else {
        sol += dad[i] != root; 
        dad[i] = root; 
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    ++t;
    if (bio[i] > 0) continue;
    c = -1;
    find_cycle(i);
    if (c == -1) continue;
    if (root == -1) root = c;
    sol += dad[c] != root;
    dad[c] = root;
  }

  printf("%d\n", sol);
  for (int i = 0; i < n; ++i)
    printf("%d ", dad[i] + 1);
  
  printf("\n");

  return 0;

}

