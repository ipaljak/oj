#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int k;

llint sum, target;
llint s[16];

map<llint, int> box, nxt;
set<llint> node, bio;
vector<vector<llint>> dp[1 << 15];

bool box_cmp(const pair<llint, int> &a, const pair<llint, int> &b) {
  return box[a.first] < box[b.first];
}

void find_cycles() {
  for (llint curr : node) {
    if (bio.find(curr) != bio.end()) continue;
    set<llint> visited;
    bio.insert(curr); visited.insert(curr);
    bool is_cycle = false;
    while (nxt.find(curr) != nxt.end()) {
      curr = nxt[curr];
      if (visited.find(curr) != visited.end()) { is_cycle = true; break; }
      if (bio.find(curr) != bio.end()) break;
      bio.insert(curr);
      visited.insert(curr);
    }

    if (!is_cycle) continue;

    bool ok = true;
    int mask = 1 << box[curr];
    vector<llint> cycle = {curr};
    llint start = curr;
    curr = nxt[curr];
    while (curr != start) {
      int b = box[curr];
      if (mask & (1 << b)) { ok = false; break; }
      mask |= 1 << b;
      cycle.push_back(curr);
      curr = nxt[curr];
    }

    if (!ok) continue;
    if (dp[mask].size() == 0) dp[mask].push_back(cycle);
  }
}

int main(void) {
  scanf("%d", &k);
  for (int i = 0; i < k; ++i) {
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; ++j) {
      llint x;
      scanf("%lld", &x);
      box[x] = i;
      node.insert(x);
      s[i] += x;
      sum += x;
    }
  }

  if (abs(sum) % k != 0) {
    printf("No\n");
    return 0;
  }

  target = sum / k;
  for (llint x : node) {
    llint y = target - (s[box[x]] - x);
    if (node.find(y) == node.end()) continue;
    nxt[x] = y;
  }

  find_cycles();

  for (int i = 1; i < 1 << k; ++i) {
    if (!dp[i].empty()) continue;
    for (int j = i; j > 0; j = (j - 1) & i) {
      assert((i & j) == j);
      if (dp[j].empty()) continue;
      if (dp[i - j].empty()) continue;
      for (auto x : dp[j]) dp[i].push_back(x);
      for (auto x : dp[i - j]) dp[i].push_back(x);
      break;
    }
  }

  if (dp[(1 << k) - 1].empty()) {
    printf("No\n");
    return 0;
  }

  vector<pair<llint, int>> sol;
  for (auto v : dp[(1 << k) - 1]) {
    for (int i = 0; i < (int) v.size(); ++i) {
      int prv = (i - 1 + (int) v.size()) % ((int) v.size());
      sol.emplace_back(v[i], box[v[prv]]);
    }
  }

  assert(sol.size() == k);
  sort(sol.begin(), sol.end(), box_cmp);
  printf("Yes\n");
  for (auto &p : sol)
    printf("%lld %d\n", p.first, p.second + 1);
  return 0;
}
