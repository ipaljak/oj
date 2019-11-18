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
int a[MAXN];

vector<int> sol;

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  set<int> s, bio;
  int last = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      if (bio.find(a[i]) != bio.end()) {
        printf("-1\n");
        return 0;
      }
      s.insert(a[i]);
      bio.insert(a[i]);
    } else {
      if (s.find(-a[i]) == s.end()) {
        printf("-1\n");
        return 0;
      }
      s.erase(-a[i]);
    }
    if (s.empty()) {
      sol.push_back(i - last);
      last = i;
      bio.clear();
    }
  }

  if (!s.empty()) {
    printf("-1\n");
    return 0;
  }

  printf("%d\n", (int) sol.size());
  for (int x : sol) printf("%d ", x);
  printf("\n");
  return 0;
}
