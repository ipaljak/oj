#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int t, n;
int a[MAXN], ret[MAXN];

vector<int> v[MAXN];

void init() {
  for (int i = 0; i <= n + 2; ++i) {
    v[i].clear();
    v[i].push_back(0);
    ret[i] = MAXN;
  }
}

void solve() {
  scanf("%d", &n); init();
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    v[a[i]].push_back(i + 1);
  }

  set<int> ss;
  for (int i = 0; i < n; ++i) ss.insert(a[i]);

  //sort(a, a + n);
  int lst = n;
  for (int ai : ss) {
    v[ai].push_back(n + 1);
    //if (ai == 5) for (int x : v[ai]) TRACE(x);
    int md = -1;
    for (int j = 1; j < (int) v[ai].size(); ++j)
      md = max(md, v[ai][j] - v[ai][j - 1]);
    if (md != -1 && md <= lst) {
      for (int j = lst; j >= max(0, md); --j) ret[j] = ai;
      lst = md - 1;
    }
    //TRACE(ai _ md _ lst);
  }

  for (int i = 1; i <= n; ++i) {
    if (ret[i] == MAXN) ret[i] = -1;
    printf("%d ", ret[i]);
  }
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
