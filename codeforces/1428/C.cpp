#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;

int t, n;
char s[MAXN];

int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s); n = strlen(s);
    stack<char> S;
    for (int i = 0; i < n; ++i) {
      if (!S.empty() && s[i] == 'B') {
        S.pop();
        continue;
      }
      S.push(s[i]);
    }
    printf("%d\n", (int) S.size());
  }
  return 0;
}
