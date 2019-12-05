#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int a, b, c, d;

vector<int> L, R;

void check() {
  int A = a, B = b, C = c, D = d;
  //TRACE(A _ B _ C _ D);
  vector<int> sol;
  for (int i = 0; i < L.size(); ++i) sol.push_back(L[i]);
  if (sol.empty() && C + B > 0 && C >= B) { sol.push_back(2); --C; }
  if (sol.empty() && C + B > 0 && B > C) { sol.push_back(1); --B; }
  while (B + C > 0) {
    if (sol.back() == 1) {
      if (C == 0) return;
      sol.push_back(2); --C;
    } else {
      if (B == 0) return;
      sol.push_back(1); --B;
    }
  }
  for (int i = 0; i < R.size(); ++i) sol.push_back(R[i]);
  for (int i = 1; i < sol.size(); ++i)
    if (abs(sol[i] - sol[i - 1]) != 1) return;

  printf("YES\n");
  for (int x : sol) printf("%d ", x);
  printf("\n");
  exit(0);
}

int main(void) {
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if (a > b + 1 || d > c + 1) {
    printf("NO\n");
    return 0;
  }

  for (int i = 0; i < a; ++i) {
    L.push_back(0);
    L.push_back(1);
    --b;
  }

  if (b == -1) { L.pop_back(); ++b; }

  for (int i = 0; i < d; ++i) {
    R.push_back(3);
    R.push_back(2);
    --c;
  }

  if (c == -1) { R.pop_back(); ++c; }

  check();
  reverse(L.begin(), L.end());
  check();
  reverse(L.begin(), L.end());
  reverse(R.begin(), R.end());
  check();
  reverse(L.begin(), L.end());
  check();

 printf("NO\n");

 return 0;
}
