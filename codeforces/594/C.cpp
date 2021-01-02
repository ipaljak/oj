#include <bits/stdc++.h>

using namespace std;

typedef long long llint;

struct Magnet {
  int id;
  double x, y;
  Magnet() {}
  Magnet(int id, double x, double y) : id(id), x(x), y(y) {}
};

const llint INF = 2e18;

int n, k;

vector<Magnet> v, xx, yy;
set<pair<pair<int, int>, pair<int, int>>> bio;

inline bool cmp_x(const Magnet &A, const Magnet &B) { return A.x < B.x; }
inline bool cmp_y(const Magnet &A, const Magnet &B) { return A.y < B.y; }

llint dim(int x_lo, int x_hi, int y_lo, int y_hi) {
  double x = xx[x_hi].x - xx[x_lo].x, y = yy[y_hi].y - yy[y_lo].y;
  return max(1LL, (llint)ceil(x)) * max(1LL, (llint)ceil(y));
}

llint solve(int k, int x_lo, int x_hi, int y_lo, int y_hi, set<int> &s) {
  while (x_lo <= x_hi && s.find(xx[x_lo].id) != s.end()) ++x_lo;
  while (x_lo <= x_hi && s.find(xx[x_hi].id) != s.end()) --x_hi;
  while (y_lo <= y_hi && s.find(yy[y_lo].id) != s.end()) ++y_lo;
  while (y_lo <= y_hi && s.find(yy[y_hi].id) != s.end()) --y_hi;

  if (x_lo > x_hi || y_lo > y_hi || k < 0 ||
      bio.find({{x_lo, x_hi}, {y_lo, y_hi}}) != bio.end())
    return INF;

  bio.insert({{x_lo, x_hi}, {y_lo, y_hi}});
  llint ret = dim(x_lo, x_hi, y_lo, y_hi);

  s.insert(xx[x_lo].id);
  ret = min(ret, solve(k - 1, x_lo + 1, x_hi, y_lo, y_hi, s));
  s.erase(xx[x_lo].id);

  s.insert(xx[x_hi].id);
  ret = min(ret, solve(k - 1, x_lo, x_hi - 1, y_lo, y_hi, s));
  s.erase(xx[x_hi].id);

  s.insert(yy[y_lo].id);
  ret = min(ret, solve(k - 1, x_lo, x_hi, y_lo + 1, y_hi, s));
  s.erase(yy[y_lo].id);

  s.insert(yy[y_hi].id);
  ret = min(ret, solve(k - 1, x_lo, x_hi, y_lo, y_hi - 1, s));
  s.erase(yy[y_hi].id);

  return ret;
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    xx.emplace_back(i, (double)(a + c) / 2.0, (double)(b + d) / 2.0);
    yy.emplace_back(i, (double)(a + c) / 2.0, (double)(b + d) / 2.0);
  }

  sort(xx.begin(), xx.end(), cmp_x);
  sort(yy.begin(), yy.end(), cmp_y);

  set<int> s;
  printf("%lld\n", solve(k, 0, xx.size() - 1, 0, yy.size() - 1, s));
  return 0;
}
