#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int n;
    vector<int> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int x; scanf("%d", &x);
      v.push_back(x);
    }

    int sol = 0;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] < i + 1) break;
      sol = i;
    }
    printf("%d\n", sol + 1);
  }
  return 0;
}
