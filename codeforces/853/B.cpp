#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int MAXD = 1e6 + 10;
const llint INF = 1e18;

struct Flight {
  int day, city, price;
  Flight() {}
  Flight(int _day, int _city, int _price)
      : day(_day), city(_city), price(_price) {}
};

int n, m, k, fwd_lo, bck_hi;
llint mn_fwd[MAXN], mn_bck[MAXN];

llint fwd_cost[MAXD], bck_cost[MAXD];

vector<Flight> fwd, bck;

bool cmp(const Flight &A, const Flight &B) {
  return A.day < B.day;
}

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int d, f, t, c;
    scanf("%d%d%d%d", &d, &f, &t, &c);
    if (t == 0) fwd.emplace_back(d, f, c);
    if (f == 0) bck.emplace_back(d, t, c);
  }

  sort(fwd.begin(), fwd.end(), cmp);
  sort(bck.begin(), bck.end(), cmp);

  for (int i = 1; i <= n; ++i) mn_fwd[i] = mn_bck[i] = INF;

  set<int> s;
  fwd_cost[0] = INF;
  int fwd_ptr = 0;
  bool complete = false;
  for (int i = 1; i < MAXD; ++i) {
    fwd_cost[i] = fwd_cost[i - 1];
    while (fwd_ptr < (int) fwd.size() && fwd[fwd_ptr].day == i) {
      int city = fwd[fwd_ptr].city;
      llint price = (llint) fwd[fwd_ptr].price;
      if (complete) {
        fwd_cost[i] = min(fwd_cost[i], fwd_cost[i] - mn_fwd[city] + price);
        mn_fwd[city] = min(mn_fwd[city], price);
      } else {
        mn_fwd[city] = min(mn_fwd[city], price);
        s.insert(city);
      }
      ++fwd_ptr;
    }
    if (!complete && s.size() == n) {
      complete = true;
      fwd_cost[i] = 0;
      for (int j = 1; j <= n; ++j) fwd_cost[i] += (llint) mn_fwd[j];
    }
  }

  s.clear();
  bck_cost[MAXD - 1] = INF;
  int bck_ptr = bck.size() - 1;
  complete = false;
  for (int i = MAXD - 2; i >= 0; --i) {
    bck_cost[i] = bck_cost[i + 1];
    while (bck_ptr >= 0 && bck[bck_ptr].day == i) {
      int city = bck[bck_ptr].city;
      llint price = (llint) bck[bck_ptr].price;
      if (complete) {
        bck_cost[i] = min(bck_cost[i], bck_cost[i] - mn_bck[city] + price);
        mn_bck[city] = min(mn_bck[city], price);
      } else {
        mn_bck[city] = min(mn_bck[city], price);
        s.insert(city);
      }
      --bck_ptr;
    }
    if (!complete && s.size() == n) {
      complete = true;
      bck_cost[i] = 0;
      for (int j = 1; j <= n; ++j) bck_cost[i] += (llint) mn_bck[j];
    }
  }

  llint sol = INF;
  for (int i = 0; i + k + 1 < MAXD; ++i)
    sol = min(sol, fwd_cost[i] + bck_cost[i + k + 1]);

  //for (int i = 0; i <= 15; ++i) printf("%lld ", fwd_cost[i]);
  //printf("\n");
  //for (int i = 0; i <= 15; ++i) printf("%lld ", bck_cost[i]);
  //printf("\n");

  if (sol == INF) printf("-1\n"); else printf("%lld\n", sol);
  return 0;
}
