#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 1e5 + 10;

bool bio[MAXN];

int n;
int cnt[MAXN];

vector<pair<int, int>> v[MAXN];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n - 2; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); --a; --b; --c;
    v[a].emplace_back(b, c);
    v[b].emplace_back(a, c);
    v[c].emplace_back(a, b);
    ++cnt[a];
    ++cnt[b];
    ++cnt[c];
  }

  int curr = -1;
  for (int i = 0; i < n; ++i)
    if (cnt[i] == 1) curr = i;

  for (int i = 0; i < n; ++i) {
    printf("%d ", curr + 1);
    bio[curr] = true;
    int nxt = -1;
    for (auto &p : v[curr]) {
      if (bio[p.first] && !bio[p.second]) nxt = p.second;
      if (bio[p.second] && !bio[p.first]) nxt = p.first;
      if (i == 0 && cnt[p.first] == 2) nxt = p.first;
      if (i == 0 && cnt[p.second] == 2) nxt = p.second;
    }
    curr = nxt;
  }

  printf("\n");

  return 0;
}
