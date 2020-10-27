#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
int a[MAXN];

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

  vector<int> l;
  l.push_back(1);

  int cl = 0, cl_ptr = 0, lst = -1, nl = 0;
  for (int i = 1; i < n; ++i) {
    //TRACE(cl _ cl_ptr _ lst _ nl);
    if (a[i] > lst) {
      lst = a[i];
      ++nl;
      continue;
    }
    cl_ptr++;
    if (cl_ptr == l[cl]) {
      l.push_back(nl);
      cl++;
      cl_ptr = 0;
      nl = 1;
      lst = a[i];
    } else {
      lst = a[i];
      ++nl;
    }
  }

  printf("%d\n", (int) l.size());
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
