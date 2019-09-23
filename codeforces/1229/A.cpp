#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 7010;

bool bio[MAXN];

int n;
int b[MAXN], cnt[MAXN];

llint a[MAXN];

vector<int> v[MAXN];

bool better(int i, int j) {
  return a[i] > (a[i] & a[j]);
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (!better(i, j)) { ++cnt[i]; v[j].push_back(i); }
      if (!better(j, i)) { ++cnt[j]; v[i].push_back(j); }
    }
  }

  //for (int i = 0; i < n; ++i)
    //printf("%d ", cnt[i]);
  //printf("\n");

  queue<int> Q;
  for (int i = 0; i < n; ++i)
    if (cnt[i] == 0) Q.push(i);

  while (!Q.empty()) {
    int curr = Q.front(); Q.pop();
    bio[curr] = true;
    for (int nxt : v[curr]) {
      --cnt[nxt];
      //TRACE(nxt _ cnt[nxt]);
      if (cnt[nxt] == 0 && !bio[nxt]) {
        bio[nxt] = true;
        Q.push(nxt);
      };
    }
  }

  llint sol = 0;
  for (int i = 0; i < n; ++i)
    if (!bio[i]) sol += (llint) b[i];

  printf("%lld\n", sol);
  return 0;
}
