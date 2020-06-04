#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 10;

bool bio[MAXN];

int n;
int a[MAXN], b[MAXN], aa[MAXN], bb[MAXN];

int deg[1 << 20];
map<pair<int, int>, vector<int>> id;

vector<pair<int, int>> e[1 << 20];

stack<int> path;

bool euler(int x, bool print) {
  for (int i = 0; i < n; ++i) {
    bio[i] = false;
    a[i] = aa[i] & ((1 << x) - 1);
    b[i] = bb[i] & ((1 << x) - 1);
    deg[a[i]] = deg[b[i]] = 0;
    e[a[i]].clear();
    e[b[i]].clear();
  }
  for (int i = 0; i < n; ++i) {
    deg[a[i]]++;
    deg[b[i]]++;
    e[a[i]].emplace_back(b[i], i);
    if (a[i] != b[i])
      e[b[i]].emplace_back(a[i], i);
  }

  for (int i = 0; i < n; ++i)
    if (deg[a[i]] % 2 || deg[b[i]] % 2) return false;

  vector<int> ret;
  int node = a[0];
  path.push(node);

  while (!path.empty()) {
    //TRACE(node);
    int nxt = -1;
    while (!e[node].empty() && bio[e[node].rbegin()->second])
      e[node].pop_back();
    if (!e[node].empty()) {
      path.push(node);
      nxt = e[node].rbegin()->first;
      bio[e[node].rbegin()->second] = true;
      e[node].pop_back();
      node = nxt;
    } else {
      ret.push_back(node);
      node = path.top();
      path.pop();
    }
  }

  if (!print) return ret.size() == n + 1;

  if (ret.size() == n + 1) {
    printf("%d\n", x);
    for (int i = 0; i < n; ++i) {
      int aa = a[i] & ((1 << x) - 1);
      int bb = b[i] & ((1 << x) - 1);
      id[{aa, bb}].push_back(i);
    }
    for (int i = ret.size() - 2; i >= 0; --i) {
      int a = ret[i + 1], b = ret[i];
      if (id.find({a, b}) != id.end() && id[{a, b}].size() != 0) {
        int x = *id[{a, b}].rbegin();
        id[{a, b}].pop_back();
        printf("%d %d ", 2 * x + 1, 2 * x + 2);
      } else {
        int x = *id[{b, a}].rbegin();
        id[{b, a}].pop_back();
        printf("%d %d ", 2 * x + 2, 2 * x + 1);
      }
    }
    printf("\n");
    exit(0);
  }
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &aa[i], &bb[i]);
  }

  int lo = 0, hi = 20;
  while (lo < hi) {
    int mid = (lo + hi) / 2 + 1;
    if (euler(mid, false)) lo = mid; else hi = mid - 1;
  }
  euler(lo, true);

  return 0;
}
