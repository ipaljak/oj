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

const int MAXN = 1005;

bool bio[MAXN];

int n, m, k;
int c[MAXN];

vector <int> v[MAXN];

int dfs(int node) {
  int ret = 1;
  if (bio[node])
    return 0;
  bio[node] = true;
  for (int next : v[node]) 
    ret += dfs(next);
  return ret;
}

int main(void) {

  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &c[i]);
    --c[i];
  }

  for (int i = 0; i < m; ++i) {
    int a, b; 
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector <int> comp;
  for (int i = 0; i < k; ++i) 
    comp.push_back(dfs(c[i]));

  sort(comp.begin(), comp.end());

  int other = 0;
  for (int i = 0; i < n; ++i)
    other += !bio[i];

//  for (int x : comp)
//    TRACE(x);
//
//  TRACE(other);
//
  llint sol = 0;
  for (int x : comp)
    sol += (llint) x * (x - 1) / 2;

  sol += (llint) other * (other - 1) / 2;
  sol += other * comp[comp.size() - 1];

  printf("%lld\n", sol - m);

  return 0;

}
