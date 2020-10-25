#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int n;
int sol[MAXN];

stack<pair<int, int>> s;

int main(void) {
  scanf("%d", &n);
  int ptr = 0;
  for (int i = 0; i < 2 * n; ++i) {
    char t[2];
    scanf("%s", t);
    if (t[0] == '+') {
      s.push({ptr++, 1});
      continue;
    }
    int x;
    scanf("%d", &x);
    if (s.empty() || s.top().second > x) {
      printf("NO\n");
      return 0;
    }
    sol[s.top().first] = x;
    s.pop();
    if (!s.empty()) s.top().second = max(s.top().second, x + 1);
  }

  printf("YES\n");
  for (int i = 0; i < n; ++i) printf("%d ", sol[i]);
  return 0;
}
