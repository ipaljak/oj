#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 998244353;
const int MAXN = 3e5 + 10;

int n;
int a[MAXN], b[MAXN], fact[MAXN];

map<pair<int, int>, int> cnt;
map<int, int> a_cnt, b_cnt;

int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

int mul(int a, int b) {
  return (llint) a * b % MOD;
}

inline void init() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = mul(i, fact[i - 1]);
}

int main(void) {
  init();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    cnt[{a[i], b[i]}]++;
    a_cnt[a[i]]++;
    b_cnt[b[i]]++;
  }

  sort(a, a + n);
  sort(b, b + n);

  int total = fact[n];
  int aa = 1, bb = 1, ab = 1;

  for (auto &kv : a_cnt)
    aa = mul(aa, fact[kv.second]);

  for (auto &kv : b_cnt)
    bb = mul(bb, fact[kv.second]);

  int x = 0;
  for (int i = 0; i < n; ++i) {
    if (i != 0 && a[i] == a[i - 1] && b[i] == b[i - 1]) continue;
    auto it = cnt.find({a[i], b[i]});
    if (it == cnt.end()) {
      ab = 0;
      continue;
    }
    ab = mul(ab, fact[it->second]);
    x += it->second;
  }

  if (x != n) ab = 0;
  printf("%d\n", add(total, add(-aa, add(-bb, ab))));

  return 0;
}
