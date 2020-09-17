#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, q;

llint pos, neg;
llint d[MAXN], a[MAXN];

inline void del(int i) {
  if (d[i] < 0) neg -= -d[i];
  if (d[i] > 0) pos -= d[i];
}

inline void upd(int i) {
  if (d[i] < 0) neg += -d[i];
  if (d[i] > 0) pos += d[i];
}

pair<llint, llint> eval(llint x) {
  llint y = (llint) a[0] - x + pos;
  return {x, y};
}

llint bs() {
  llint lo = -1e15, hi = 1e15;
  while (lo < hi) {
    llint mid = (lo + hi) / 2 + (rand() % 2);
    auto p = eval(mid);
    if (p.first <= p.second) lo = mid; else hi = mid - 1;
  }
  auto p = eval(lo);
  return max(p.first, p.second);
}

int main(void) {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);

  for (int i = 1; i < n; ++i) {
    d[i] = (a[i] - a[i - 1]);
    if (d[i] < 0) neg += -d[i]; else pos += d[i];
  }

  printf("%lld\n", bs());
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x); --l; --r;
    if (l == 0) a[0] += (llint) x;
    if (l > 0) {
      del(l);
      d[l] += (llint) x;
      upd(l);
    }
    if (r < n - 1) {
      del(r + 1);
      d[r + 1] -= (llint) x;
      upd(r + 1);
    }
    printf("%lld\n", bs());
  }
  return 0;
}
