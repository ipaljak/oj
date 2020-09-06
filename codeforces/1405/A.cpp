#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

int t, n;
vector<int> v;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n); v.clear();
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      v.emplace_back(x);
    }
    reverse(v.begin(), v.end());
    for (int x : v) printf("%d ", x);
    printf("\n");
  }
  return 0;
}
