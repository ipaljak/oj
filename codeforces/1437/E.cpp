#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 10;
const int INF = 1e9;

int n, k;
int a[MAXN], b[MAXN];

int lis(const vector<int> &v) {
  //for (int x : v) TRACE(x);
  int N = v.size();
  vector<int> d(N + 1, INF);
  d[0] = -INF;

  for (int i = 0; i < N; i++) {
    int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
    if (d[j - 1] <= v[i] && v[i] <= d[j]) d[j] = v[i];
  }

  int ret = 0;
  for (int i = 0; i <= N; i++) {
    if (d[i] < INF) ret = i;
  }
  //TRACE(ret);
  return ret;
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }

  for (int i = 0; i < n; ++i) a[i] -= i + 1;
  for (int i = 1; i < k; ++i) {
    if (a[b[i - 1]] > a[b[i]]) {
      printf("-1\n");
      return 0;
    }
  }

  vector<int> ind;
  ind.push_back(-1);
  for (int i = 0; i < k; ++i) ind.push_back(b[i]);
  ind.push_back(n);
  int sol = n - k;

  for (int i = 1; i < (int)ind.size(); ++i) {
    vector<int> v;
    for (int j = ind[i - 1] + 1; j < ind[i]; ++j) {
      if (ind[i - 1] != -1 && a[j] < a[ind[i - 1]]) continue;
      if (ind[i] != n && a[j] > a[ind[i]]) continue;
      v.push_back(a[j]);
    }
    sol -= lis(v);
  }

  printf("%d\n", sol);
  return 0;
}
