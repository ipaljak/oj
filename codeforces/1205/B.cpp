#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int cnt[60];

llint a[MAXN];

int main(void) {
  scanf("%d", &n);
  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[ptr]);
    if (a[ptr] == 0) continue;
    for (int j = 0; j < 60; ++j)
      if (a[ptr] & (1LL << j)) ++cnt[j];
    ++ptr;
  }

  n = ptr;

  for (int i = 0; i < 60; ++i) {
    if (cnt[i] > 2) {
      printf("3\n");
      return 0;
    }
  }

  vector<int> v[n];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = 0; k < 60; ++k) {
        if ((a[i] & (1LL << k)) != 0 && (a[j] & (1LL << k)) != 0) {
          v[i].push_back(j);
          v[j].push_back(i);
          break;
        }
      }
    }
  }

  //for (int i = 0; i < n; ++i) {
    //printf("%d: ", i);
    //for (int j : v[i])
      //printf("%d ", j);
    //printf("\n");
  //}

  int dist[n];
  int sol = n + 1;
  for (int i = 0; i < n; ++i) {
    memset(dist, -1, sizeof dist);
    dist[i] = 0;
    queue<pair<int, int>> Q;
    Q.push({i, -1});
    while (!Q.empty()) {
      auto p = Q.front(); Q.pop();
      int curr = p.first, dad = p.second;
      for (int nxt : v[curr]) {
        if (nxt == dad) continue;
        if (dist[nxt] != -1) {
          sol = min(sol, dist[curr] + dist[nxt] + 1);
          continue;
        }
        dist[nxt] = dist[curr] + 1;
        Q.push({nxt, curr});
      }
    }
  }

  if (sol == n + 1) sol = -1;
  printf("%d\n", sol);

  return 0;
}
