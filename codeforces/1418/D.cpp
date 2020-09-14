#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, q;
set<int> s;
multiset<int> pq;

int ans() {
  if (s.empty()) return 0;
  int ret = *s.rbegin() - *s.begin();
  if (!pq.empty()) ret -= *pq.rbegin();
  return ret;
}

int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    s.insert(x);
  }

  int prev = -1;
  for (int x : s) {
    if (prev == -1) {
      prev = x;
      continue;
    }
    pq.insert(x - prev);
    prev = x;
  }

  printf("%d\n", ans());
  for (int i = 0; i < q; ++i) {
    int t, x;
    scanf("%d%d", &t, &x);
    if (t == 0) {
      auto it = s.find(x);
      auto itl = it, itr = it;
      bool border = x == *s.begin() || x == *s.rbegin();
      if (x != *s.begin()) {
        itl--;
        pq.erase(pq.find(*it - *itl));
      }
      if (x != *s.rbegin()) {
        itr++;
        pq.erase(pq.find(*itr - *it));
      }
      if (!border) pq.insert(*itr - *itl);
      s.erase(it);
    } else {
      s.insert(x);
      auto it = s.find(x);
      auto itl = it, itr = it;
      bool border = x == *s.begin() || x == *s.rbegin();
      if (x != *s.begin()) {
        itl--;
        pq.insert(*it - *itl);
      }
      if (x != *s.rbegin()) {
        itr++;
        pq.insert(*itr - *it);
      }
      if (!border) pq.erase(pq.find(*itr - *itl));
    }
    printf("%d\n", ans());
  }
  return 0;
}
