#include <bits/stdc++.h>

using namespace std;

//#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;
const int MOD = 10002029;
const int EXP = 1031;
const int INF = 2e9;

struct Event {
  int id, x, add;
  Event() {}
  Event(int id, int x, int add) : id(id), x(x), add(add) {}
  friend bool operator<(const Event &A, const Event &B) {
    if (A.x == B.x) return A.add > B.add;
    return A.x < B.x;
  }
};

int n;
int l1[MAXN], r1[MAXN], l2[MAXN], r2[MAXN];
int h1[MAXN], h2[MAXN];

vector<Event> e1, e2;

int add(int a, int b) {
  if (a + b < 0) return a + b + MOD;
  if (a + b >= MOD) return a + b - MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

int mypow(int b, int e) {
  int ret = 1;
  while (e) {
    if (e & 1) {
      ret = mul(ret, b);
      --e;
    }
    b = mul(b, b);
    e /= 2;
  }
  return ret;
}

void sweep(const vector<Event> &events, int *h, int *l, int *r) {
  int hh = 0;
  vector<pair<int, int>> vend;
  for (int i = 0; i < events.size(); ++i) {
    const auto &e = events[i];
    if (e.add > 0) {
      hh = add(hh, e.add);
      continue;
    }
    int j = i;
    int hh_diff = 0;
    while (j < events.size() && events[j].x == events[i].x) {
      vend.emplace_back(events[j].x, -events[j].add);
      hh_diff = add(hh_diff, events[j].add);
      ++j;
    }
    while (i < j) {
      h[events[i].id] = hh;
      //TRACE("Stavljam na " _ events[i].id _ hh);
      ++i;
    }
    --i;
    //TRACE(hh_diff _ j);
    hh = add(hh, hh_diff);
  }

  //for (int i = 0; i < n; ++i) printf("%d ", h[i]);
  //printf("\n");

  sort(vend.begin(), vend.end());
  vector<int> psum(vend.size(), 0);
  psum[0] = vend[0].second;
  for (int i = 1; i < vend.size(); ++i)
    psum[i] = add(psum[i - 1], vend[i].second);

  for (int i = 0; i < n; ++i) {
    int lo =
        (int)(lower_bound(vend.begin(), vend.end(), make_pair(l[i], -INF)) -
              vend.begin());
    int hi =
        (int)(upper_bound(vend.begin(), vend.end(), make_pair(r[i] - 1, INF)) -
              vend.begin()) -
        1;
    int hdiff = 0;
    if (lo <= hi) {
      hdiff = psum[hi];
      if (lo > 0) hdiff = add(hdiff, -psum[lo - 1]);
    }
    h[i] = add(h[i], hdiff);
  }

}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &l1[i], &r1[i], &l2[i], &r2[i]);
    e1.emplace_back(i, l1[i], mypow((i + 3135), EXP));
    e1.emplace_back(i, r1[i], -mypow((i + 3135), EXP));
    e2.emplace_back(i, l2[i], mypow((i + 3135), EXP));
    e2.emplace_back(i, r2[i], -mypow((i + 3135), EXP));
  }

  sort(e1.begin(), e1.end());
  sort(e2.begin(), e2.end());

  //for (auto x : e1) TRACE(x.x _ x.id _ x.add);

  sweep(e1, h1, l1, r1);
  sweep(e2, h2, l2, r2);

  //for (int i = 0; i < n; ++i) printf("%d ", h1[i]); printf("\n");
  //for (int i = 0; i < n; ++i) printf("%d ", h2[i]); printf("\n");

  bool yes = true;
  for (int i = 0; i < n; ++i)
    yes &= h1[i] == h2[i];

  if (yes) printf("YES\n"); else printf("NO\n");
  return 0;
}
