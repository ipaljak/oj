#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 10;

int n, h;

vector<int> v;

bool check(vector<int> &v) {
  sort(v.begin(), v.end());
  int hh = 0;
  for (int i = (int) v.size() - 1; i >= 0; i -= 2) {
    int curr = v[i];
    if (i - 1 >= 0) curr = max(curr, v[i - 1]);
    hh += curr;
    if (hh > h) return false;
  }
  return true;
}

int main(void) {
  scanf("%d%d", &n, &h);
  int sol = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
    if (check(v)) sol = i + 1;
  }

  printf("%d\n", sol);
  return 0;
}
