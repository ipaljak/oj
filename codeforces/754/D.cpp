#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN = 3e5 + 10;

struct event {
  int id, l, r;
  event() {}
  event(int _id, int _l, int _r) {
    id = _id;
    l = _l;
    r = _r;
  }
  friend bool operator < (const event &A, const event &B) {
    return A.r > B.r;
  }
};

int n, k;

priority_queue <event> pq;
priority_queue <event> mono;

set <int> rek;

vector <event> E;

inline bool cmp_l(const event &A, const event &B) {
  if (A.l == B.l)
    return A.r < B.r;
  return A.l < B.l;
}

inline bool cmp_id(const event &A, const event &B) {
  return A.id < B.id;
}

inline bool cmp_r(const int &a, const int &b) {
  return E[a].r > E[b].r;
}

int clear_until(priority_queue <event> &q, int t) {
  int ret = 0;
  while (!q.empty() && q.top().r < t) {
    ++ret;
    if (rek.find(q.top().id) != rek.end())
      rek.erase(rek.find(q.top().id));
    q.pop();
  }
  return ret;
}
 
int main(void) {
  
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int l, r; scanf("%d%d", &l, &r);
    E.emplace_back(i, l, r);
  }

  sort(E.begin(), E.end(), cmp_l);

  int curr = 0, sol = 0, t = -1e9 - 5, _l, _r;

  for (auto &e : E) {

    t = e.l;

    curr -= clear_until(pq, t);
    clear_until(mono, t);

    ++curr;
    rek.insert(e.id);

    mono.push(e);

    if (curr >= k) {
      if (mono.top().r - e.l + 1 > sol) {
        sol = mono.top().r - e.l + 1;
        _l = e.l;
        _r = mono.top().r;
      }
      mono.pop();
    }

    pq.push(e);

  }

  printf("%d\n", sol);

  vector <int> ss;
  if (sol == 0) {
    for (int i = 0; i < k; ++i)
      ss.push_back(i);
  } else {
    for (auto &e : E) 
      if (e.l <= _l && e.r >= _r)
        ss.push_back(e.id);
  }

  for (int i = 0; i < k; ++i)
    printf("%d ", ss[i] + 1);

  printf("\n");

  return 0;

}

