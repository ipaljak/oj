#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int INF = 2e9;

int n, mx;
int a[7], b[MAXN];

vector<int> v[MAXN];
set<pair<int, int>> str;
set<int> s;

int main(void) {
  for (int i = 0; i < 6; ++i) scanf("%d", &a[i]);
  sort(a, a + 6);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    for (int j = 5; j >= 0; --j) {
      v[i].push_back(b[i] - a[j]);
      s.insert(b[i] - a[j]);
    }
    str.insert({v[i][0], i});
    mx = max(mx, v[i][0]);
  }

  int sol = mx;
  for (int f : s) {
    sol = min(sol, mx - f);
    while (!str.empty() && str.begin()->first == f) {
      int v = -1;
      for (int k = 5; k >= 0; --k) {
        if (b[str.begin()->second] - a[k] > f) {
          v = b[str.begin()->second] - a[k];
          break;
        }
      }
      if (v == -1) {
        printf("%d\n", sol);
        return 0;
      }
      mx = max(mx, v);
      str.insert({v, str.begin()->second});
      str.erase(str.begin());
    }
  }

  printf("%d\n", sol);
  return 0;
}
