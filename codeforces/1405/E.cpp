#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

struct Query {
  int id, l, r;
  Query() {}
  Query(int id, int l, int r): id(id), l(l), r(r) {}
};

int n, q;
int a[MAXN], ans[MAXN], l[MAXN];

vector<Query> Q;

int add(int i, int x) {
  for (; i <= n + 5; i += i & -i) l[i] += x;
}

int sum(int i) {
  int ret = 0;
  for (; i > 0; i -= i & -i) ret += l[i];
  return ret;
}

int bs(int lo, int hi, int val) {
  while (lo < hi) {
    int mid = (lo + hi) / 2 + 1;
    if (sum(mid) >= val) lo = mid; else hi = mid - 1;
  }
  return lo;
}

int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] = i + 1 - a[i];
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r); r = n - r - 1;
    Q.emplace_back(i, l, r);
  }

  sort(Q.begin(), Q.end(),
       [](const Query &a, const Query &b) {
         return a.r < b.r;
       });

  int qit = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) {
      if (sum(1) >= a[i]) {
        int pos = bs(1, i + 1, a[i]);
        add(1, 1); add(pos + 1, -1);
      }
    }

    while (qit < (int) Q.size() && Q[qit].r == i) {
      ans[Q[qit].id] = sum(Q[qit].l + 1);
      ++qit;
    }
  }

  for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
  return 0;
}
