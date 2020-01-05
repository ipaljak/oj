#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2020;

int n, root;
int p[MAXN], c[MAXN], s[MAXN], val[MAXN];

vector<int> v[MAXN];
vector<int> subtree[MAXN];

bool cmp(int a, int b) {
  return val[a] < val[b];
}

void dfs(int node) {
  //TRACE(node);
  s[node] = 0;
  for (int nxt : v[node]) {
    dfs(nxt);
    //sort(subtree[nxt].begin(), subtree[nxt].end(), cmp);
    if (subtree[node].size() == c[node]) {
      subtree[node].push_back(node);
      val[node] = s[node]++;
    }
    for (int x : subtree[nxt]) {
      subtree[node].push_back(x);
      val[x] = s[node]++;
      if (subtree[node].size() == c[node]) {
        subtree[node].push_back(node);
        val[node] = s[node]++;
      }
    }
  }
  if (subtree[node].size() == c[node]) {
    subtree[node].push_back(node);
    val[node] = s[node]++;
  }
  //TRACE(node _ s[node] _ c[node]);
  if (c[node] > s[node]) {
    printf("NO\n");
    exit(0);
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i], &c[i]); --p[i];
    if (p[i] == -1) root = i;
    if (p[i] != -1)
      v[p[i]].push_back(i);
  }

  //TRACE(root);
  //for (int x : v[root]) TRACE(x);

  dfs(root);

  printf("YES\n");
  for (int i = 0; i < n; ++i) printf("%d ", val[i] + 1);
  printf("\n");

  return 0;
}
