#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

bool bd[MAXN];

int n;
int a[MAXN];

vector<pair<int, int>> sol;

pair<int, int> coord(pair<int, int> p) {
  return {(n - 1 - p.second), p.first};
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) bd[i] = false;
  int lst = -1;
  queue<int> dva;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 0) continue;
    while (!dva.empty() && bd[dva.front()]) dva.pop();
    if ((a[i] == 2 && dva.empty()) || (a[i] == 3 && lst == -1)) {
      printf("-1\n");
      return 0;
    }
    if (a[i] == 1) {
      sol.emplace_back(i, (n - 1) - i);
      lst = i;
      dva.push(i);
      continue;
    }
    if (a[i] == 2) {
      int xx = dva.front(); dva.pop();
      bd[i] = bd[xx] = true;
      sol.emplace_back(i, (n - 1) - xx);
      lst = i;
    }
    if (a[i] == 3) {
      sol.emplace_back(i, (n - 1) - i);
      sol.emplace_back(lst, (n - 1) - i);
      bd[i] = bd[lst] = true;
      lst = i;
    }
  }

  printf("%d\n", (int) sol.size());
  for (auto &p : sol) {
    auto c = coord(p);
    //TRACE(p.first + 1 _ p.second + 1);
    printf("%d %d\n", c.first + 1, c.second + 1);
  }
  return 0;
}
