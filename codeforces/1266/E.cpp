#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int n, q;
int a[MAXN], cnt[MAXN];

llint sum;

map<pair<int, int>, int> m;

void remove(int s, int t) {
  if (m.find({s, t}) == m.end()) return;
  int u = m[{s, t}];
  m.erase(m.find({s, t}));
  if (cnt[u] <= a[u]) ++sum;
  --cnt[u];
}

void add(int s, int t, int u) {
  m[{s, t}] = u;
  if (cnt[u] < a[u]) --sum;
  ++cnt[u];
}

int main(void) {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum += (llint) a[i];
  }

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int s, t, u;
    scanf("%d%d%d", &s, &t, &u); --s; --u;
    remove(s, t);
    if (u != -1) add(s, t, u);
    printf("%lld\n", sum);
  }

  return 0;
}
