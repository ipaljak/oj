#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

int n;
int p[MAXN];

vector<pair<int, int>> q;
set<int> s;

int loga[MAXN];
llint loga_d[MAXN];

llint sol[MAXN];

priority_queue<int> plo;
priority_queue<int, vector<int>, greater<int>> phi;

void inc(int i) {
  for ( ; i <= n + 5; i += i & -i) ++loga[i];
}

int sum(int i) {
  int ret = 0;
  for ( ; i > 0; i -= i & -i) ret += loga[i];
  return ret;
}

void inc_d(int i, llint x) {
  for ( ; i <= n + 5; i += i & -i) loga_d[i] += x;
}

llint sum_d(int i) {
  llint ret = 0;
  for ( ; i > 0; i -= i & -i) ret += loga_d[i];
  return ret;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    q.emplace_back(p[i], i);
  }

  sort(q.begin(), q.end());

  int i = 0;
  llint dist = 0, inv = 0, tot = 0;
  for (auto &x : q) {
    inc_d(x.second + 1, x.second);
    inc(x.second + 1);
    tot += (llint) x.second;
    ++i;

    if (plo.empty() || plo.top() > x.second) {
      plo.push(x.second);
    } else {
      phi.push(x.second);
    }

    while (abs((int)plo.size() - (int)phi.size()) > 1) {
      if (plo.size() < phi.size()) {
        plo.push(phi.top());
        phi.pop();
      } else {
        phi.push(plo.top());
        plo.pop();
      }
    }

    if ((int) plo.size() + 1 == (int) phi.size()) {
      plo.push(phi.top());
      phi.pop();
    }

    int med = plo.top();
    llint d_left = sum_d(med);
    llint d_right = tot - d_left - med;
    int n_left = sum(med);
    int n_right = i - n_left - 1;
    dist = (llint) n_left * med - d_left - (llint) n_left * (n_left + 1) / 2;
    dist += d_right - (llint) n_right * med - (llint) n_right * (n_right + 1) / 2;

    inv += (llint) (i - sum(x.second + 1));
    sol[x.first - 1] = dist + inv;
  }

  for (int i = 0; i < n; ++i)
    printf("%lld ", sol[i]);
  printf("\n");
  return 0;
}
