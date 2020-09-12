#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

int t, n;
int a[105];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    int sol = 0;
    for (int i = 0; i < 2; ++i) {
      bool flag = false;
      int curr  = -1;
      for (auto &p : cnt) {
        ++curr;
        if (flag) continue;
        --p.second;
        if (p.first != curr || p.second < 0) {
          sol += curr;
          flag = true;
          continue;
        }
      }
      if (!flag) sol += curr + 1;
    }
    printf("%d\n", sol);
  }
  return 0;
}
