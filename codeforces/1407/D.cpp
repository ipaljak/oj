#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

vector<int> v[MAXN];

int n;
int h[MAXN], dist[MAXN];

int bfs() {
  memset(dist, -1, sizeof dist);
  queue<int> Q;
  Q.push(0);
  dist[0] = 0;
  while (!Q.empty()) {
    int node = Q.front(); Q.pop();
    for (int nxt : v[node]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[node] + 1;
      Q.push(nxt);
    }
  }
  return dist[n - 1];
}

void get_neigh() {
  stack<int> S;
  for (int i = 0; i < n; ++i) {
    while (!S.empty() && h[S.top()] < h[i]) {
      v[S.top()].push_back(i);
      S.pop();
    }
    if (!S.empty()) {
      v[S.top()].push_back(i);
    }
    while (!S.empty() && h[S.top()] == h[i]) S.pop();
    S.push(i);
  }

  while (!S.empty()) S.pop();
  for (int i = 0; i < n; ++i) {
    while (!S.empty() && h[S.top()] > h[i]) {
      v[S.top()].push_back(i);
      S.pop();
    }
    if (!S.empty()) {
      v[S.top()].push_back(i);
    }
    while (!S.empty() && h[S.top()] == h[i]) S.pop();
    S.push(i);
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
  for (int i = 1; i < n; ++i) {
    v[i - 1].push_back(i);
  }

  get_neigh();
  //reverse(h, h + n);
  //get_neigh();

  //for (int i = 0; i < n; ++i) {
    //printf("%d: ", i + 1);
    //for (int x : v[i]) printf("%d ", x + 1);
    //printf("\n");
  //}

  printf("%d\n", bfs());
  return 0;
}
