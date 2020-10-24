#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
int p[MAXN], a[MAXN], ch[MAXN];

llint sz[MAXN];

vector<int> v[MAXN];

void dfs(int node) {
  sz[node] += (llint) a[node];
  for (int nxt : v[node]) {
    dfs(nxt);
    sz[node] += sz[nxt];
    ch[node] += ch[nxt];
  }
  if (v[node].size() == 0) ch[node]++;
}

bool check(llint val) {
  for (int i = 0; i < n; ++i) {
    if ((llint) ch[i] * val < sz[i] && !(
        (double) ch[i] * (double) val >= (double) sz[i] ||
        (llint) ch[i] / 100LL * val >= sz[i])) return false;
  }
  return true;
}

llint bs() {
  llint lo = 0, hi = 5e14;
  while (lo < hi) {
    //TRACE(lo _ hi);
    llint mid = (lo + hi) / 2LL;
    if (check(mid)) hi = mid; else lo = mid + 1;
  }
  return lo;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &p[i]); --p[i];
    v[p[i]].push_back(i);
  }

  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  dfs(0);
  //for (int i = 0; i < n; ++i) TRACE(sz[i] _ ch[i]);

  printf("%lld\n", bs());
  return 0;
}
