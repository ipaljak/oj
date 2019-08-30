#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

char curr = 'a', sol[MAXN];

int n, k;
int a[MAXN], b[MAXN], pos[MAXN];

vector<pair<int, int>> v;

void next() {
  if (curr == 'z') return;
  ++curr;
}

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]); --a[i];
    pos[a[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
  }

  for (int i = 1; i < n; ++i) {
    int l = b[i - 1], r = b[i];
    if (pos[l] > pos[r]) {
      v.emplace_back(pos[r], 1);
      v.emplace_back(pos[l], -1);
    }
  }

  sort(v.begin(), v.end());
  int v_ptr = 0, diff = 0;
  int max_k = 0;
  for (int i = 0; i < n; ++i) {
    while (v_ptr < (int) v.size() && v[v_ptr].first <= i) {
      diff += v[v_ptr].second;
      ++v_ptr;
    }
    assert(diff >= 0);
    sol[a[i]] = curr;
    max_k = max(max_k, curr - 'a' + 1);
    if (diff == 0) next();
  }

  if (max_k < k) {
    printf("NO\n");
  } else {
    printf("YES\n");
    printf("%s\n", sol);
  }

  return 0;
}
