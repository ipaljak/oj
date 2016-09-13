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

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

const int MAXN  = 200010;
const int MAXX  = 1000010;
const int BLOCK = 450; // sqrt(N) 

struct query {

  int l, r, i;
  
  query() {}

  query(int _l, int _r, int _i) {
    l = _l;
    r = _r;
    i = _i;
  }

  friend bool operator < (const query &A, const query &B) {
    if (A.l / BLOCK != B.l / BLOCK) {
      return A.l / BLOCK < B.l / BLOCK;
    }
    return A.r < B.r; 
  }

};

int n, m; 
int a[MAXN], cnt[MAXX];

llint curr;
llint ans[MAXN];

vector <query> Q;

inline void add(int ptr) {
  curr -= (llint) cnt[a[ptr]] * cnt[a[ptr]] * a[ptr];
  ++cnt[a[ptr]];
  curr += (llint) cnt[a[ptr]] * cnt[a[ptr]] * a[ptr];
}

inline void remove(int ptr) {
  curr -= (llint) cnt[a[ptr]] * cnt[a[ptr]] * a[ptr];
  --cnt[a[ptr]];
  curr += (llint) cnt[a[ptr]] * cnt[a[ptr]] * a[ptr];
}

void mo() {

  int lo = 0, hi = 0;
  curr = (llint) a[0];
  cnt[a[0]] = 1;

  sort(Q.begin(), Q.end());

  for (auto& q : Q) {
//    TRACE(q.l _ q.r);
    while (lo < q.l) remove(lo++);
    while (lo > q.l) add(--lo);
    while (hi < q.r) add(++hi);
    while (hi > q.r) remove(hi--);
    ans[q.i] = curr;
  }

}

int main(void) {

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) 
    scanf("%d", &a[i]);

  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r); --l; --r;
    Q.emplace_back(l, r, i);
  }

  mo();

  for (int i = 0; i < m; ++i) 
    printf("%lld\n", ans[i]);

  return 0;

}

