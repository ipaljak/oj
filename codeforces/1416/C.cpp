#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

int n;
int a[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  llint inv = 0;
  int x = 0;
  for (int k = 29; k >= 0; --k) {
    llint z = 0, o = 0;
    unordered_map<int, pair<int, int>> m;
    for (int i = 0; i < n; ++i) {
      int msk = (1 << 30) - 1;
      msk -= (1 << (k + 1)) - 1;
      int bit = (a[i] & (1 << k)) != 0;
      if (m.find(a[i] & msk) == m.end()) {
        m[a[i] & msk] = {bit == 0, bit == 1};
        continue;
      }
      auto p = m[a[i] & msk];
      if (bit == 0) { z += (llint) p.second; ++p.first; }
      if (bit == 1) { o += (llint) p.first; ++p.second; }
      m[a[i] & msk] = p;
      //m[a[i] & msk].push_back((a[i] & (1 << k)) != 0);
    }
    //TRACE(k);
    //llint z = 0, o = 0;
    //for (auto &p : m) {
      ////TRACE(p.first _ p.second.size());
      //int cz = 0, co = 0;
      //for (int y : p.second) {
        ////TRACE(y);
        //if (y == 0) { z += (llint) co; ++cz; }
        //if (y == 1) { o += (llint) cz; ++co; }
      //}
    //}
    //TRACE(k _ z _ o);
    if (z <= o) {
      inv += z;
    } else {
      inv += o;
      x |= 1 << k;
    }
  }

  printf("%lld %d\n", inv, x);
  return 0;
}
