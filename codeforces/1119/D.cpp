#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n, q;
llint s[MAXN], sol[MAXN];

vector<llint> vs;
vector<pair<llint, int>> vq;

int main(void) {
  scanf("%d", &n);
  set<llint> ss;
  for (int i = 0; i < n; ++i) {
    llint x;
    scanf("%lld", &x);
    ss.insert(x);
  }

  for (llint x : ss)
    vs.emplace_back(x);

  for (int i = 0; i < (int) vs.size() - 1; ++i)
    vs[i] = vs[i + 1] - vs[i];
  vs[vs.size() - 1] = 1000000000000000010LL;
  sort(vs.begin(), vs.end());
  n = (int) vs.size();

  //for (llint x : vs) printf("%lld ", x);
  //printf("\n");

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    llint l, r;
    scanf("%lld%lld", &l, &r);
    vq.emplace_back(r - l + 1, i);
  }

  sort(vq.begin(), vq.end());

  llint pref = 0;
  int curr = 0;
  for (auto &p : vq) {
    while (p.first > vs[curr]) {
      pref += vs[curr];
      ++curr;
    }
    //TRACE(p.first _ pref);
    sol[p.second] = pref;
    sol[p.second] += (llint) (n - curr) * p.first;
  }

  for (int i = 0; i < q; ++i)
    printf("%lld ", sol[i]);
  printf("\n");
  return 0;
}
