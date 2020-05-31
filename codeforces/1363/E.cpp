#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int n;
int c[MAXN], state[MAXN], one[MAXN], zero[MAXN];

llint tot[MAXN];

vector<int> v[MAXN];

void dfs(int node, int tresh, int dad) {
  one[node] += state[node] == 1;
  zero[node] += state[node] == 0;
  for (int nxt : v[node]) {
    if (nxt == dad) continue;
    dfs(nxt, min(tresh, c[nxt] + 1), node);
    one[node] += one[nxt];
    zero[node] += zero[nxt];
    tot[node] += tot[nxt];
  }
  //TRACE(node _ one[node] _ zero[node] _ tot[node]);
  if (tresh <= c[node]) return;
  int x = min(one[node], zero[node]);
  one[node] -= x;
  zero[node] -= x;
  tot[node] += (llint) c[node] * x * 2LL;
  //TRACE(node _ one[node] _ zero[node] _ tot[node]);
}

int main(void) {
  scanf("%d", &n);
  int zero = 0, one = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d%d", &c[i], &x, &y);
    if (x == y) {
      state[i] = -1;
    } else {
      state[i] = x;
      zero += x == 0;
      one += x == 1;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  if (zero != one) {
    printf("-1\n");
    return 0;
  }

  dfs(0, c[0] + 1, -1);
  printf("%lld\n", tot[0]);

  return 0;
}
