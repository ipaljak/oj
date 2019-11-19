#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int n, cnt;
int p1 = 1, p2 = 2;

int ask_ccw(int a, int b, int c) {
  ++cnt;
  assert(cnt <= 3 * n);
  printf("2 %d %d %d\n", a, b, c); fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

llint ask_area(int a, int b, int c) {
  ++cnt;
  assert(cnt <= 3 * n);
  printf("1 %d %d %d\n", a, b, c); fflush(stdout);
  llint ret;
  scanf("%lld", &ret);
  return ret;
}

vector<int> solve_half(vector<int> &v) {
  if (v.empty()) return {};
  vector<int> ll, rr;
  vector<pair<llint, int>> A;
  for (int x : v) A.emplace_back(ask_area(p1, p2, x), x);
  sort(A.begin(), A.end());
  for (int i = 0; i < (int) A.size() - 1; ++i) {
    if (ask_ccw(p1, A.back().second, A[i].second) > 0)
      ll.push_back(A[i].second);
    else
      rr.push_back(A[i].second);
  }
  reverse(ll.begin(), ll.end());
  rr.push_back(A.back().second);
  for (int x : ll) rr.push_back(x);
  return rr;
}

int main(void) {
  scanf("%d", &n);

  vector<int> l, r;
  for (int i = 3; i <= n; ++i) {
    if (ask_ccw(p1, p2, i) > 0)
      l.push_back(i);
    else
      r.push_back(i);
  }


  vector<int> L = solve_half(l);
  vector<int> R = solve_half(r);

  printf("0 %d ", p1);
  for (int x : R) printf("%d ", x);
  printf("%d ", p2);
  for (int x : L) printf("%d ", x);
  printf("\n"); fflush(stdout);

  return 0;
}
