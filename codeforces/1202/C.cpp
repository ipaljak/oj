#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
char s[MAXN];

void solve() {
  scanf("%s", s);
  n = strlen(s);
  int minw = 0, maxw = 0, minh = 0, maxh = 0;
  int currw = 0, currh = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') ++currh;
    if (s[i] == 'S') --currh;
    if (s[i] == 'A') --currw;
    if (s[i] == 'D') ++currw;
    minw = min(minw, currw);
    maxw = max(maxw, currw);
    minh = min(minh, currh);
    maxh = max(maxh, currh);
  }

  int w = maxw - minw + 1, h = maxh - minh + 1;
  int lominh = -(minh != 0), himinh = -(minh != 0), lomaxh = -(maxh != 0),
      himaxh = -(maxh != 0);
  int lominw = -(minw != 0), himinw = -(minw != 0), lomaxw = -(maxw != 0),
      himaxw = -(maxw != 0);
  int bestw = w, besth = h;

  currw = currh = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') ++currh;
    if (s[i] == 'S') --currh;
    if (s[i] == 'A') --currw;
    if (s[i] == 'D') ++currw;
    if (currh == minh) {
      if (lominh == -1) lominh = i;
      himinh = i;
    }
    if (currh == maxh) {
      if (lomaxh == -1) lomaxh = i;
      himaxh = i;
    }
    if (currw == minw) {
      if (lominw == -1) lominw = i;
      himinw = i;
    }
    if (currw == maxw) {
      if (lomaxw == -1) lomaxw = i;
      himaxw = i;
    }
  }

  if (besth > 2 && (himaxh < lominh || himinh < lomaxh)) --besth;
  if (bestw > 2 && (himaxw < lominw || himinw < lomaxw)) --bestw;

  //TRACE(w _ h _ bestw _ besth);
  printf("%lld\n", min((llint) bestw * h, (llint) besth * w));
}

int main(void) {
  scanf("%d", &t);
  while (t --> 0) solve();
  return 0;
}
