#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;


int m;
int n, T, a, b;
int hard[MAXN], t[MAXN];

map<int, int> mh, me;
set<int> event;

void solve() {
  scanf("%d%d%d%d", &n, &T, &a, &b);
  int H = 0, E = 0;
  event.clear(); mh.clear(); me.clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d", &hard[i]);
    H += hard[i];
    E += !hard[i];
  }
  //TRACE(E _ H);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
    if (hard[i]) mh[t[i]]++; else me[t[i]]++;
    event.insert(t[i] - 1);
    event.insert(t[i]);
  }

  event.insert(T);
  int sol = 0, e = 0, h = 0;
  for (int tt : event) {
    e += me[tt];
    h += mh[tt];
    //TRACE(e _ h);
    //TRACE(h * b + e * a _ tt);
    if ((llint) h * b + (llint) e * a <= (llint) tt) {
      int curr = e + h;
      int t_left = tt - h * b - e * a;
      if (t_left / a > 0) {
        int kk =  min(t_left / a, E - e);
        curr += kk;
        t_left -= kk * a;
      }
      if (t_left / b > 0) {
        int kk = min(t_left / b, H - h);
        curr += kk;
        t_left -= kk * b;
      }
      sol = max(sol, curr);
      //TRACE(sol _ tt);
    }
  }

  printf("%d\n", sol);
}

int main(void) {
  scanf("%d", &m);
  while (m--) solve();
  return 0;
}
