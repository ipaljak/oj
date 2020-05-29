#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int INF = 1e9 + 7;

int hpa, atka, defa;
int hpb, atkb, defb;
int h, a, b;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

bool check(int hpa, int atka, int defa) {
  int x = INF, y = INF;
  if (atka - defb > 0) x = ceil(hpb, atka - defb);
  if (atkb - defa > 0) y = ceil(hpa, atkb - defa);
  return x < y;
}

int main(void) {
  scanf("%d%d%d", &hpa, &atka, &defa);
  scanf("%d%d%d", &hpb, &atkb, &defb);
  scanf("%d%d%d", &h, &a, &b);

  int sol = INF;
  for (int i = 0; i < 1050; ++i)
    for (int j = 0; j < 205; ++j)
      for (int k = 0; k < 105; ++k)
        if (check(hpa + i, atka + j, defa + k))
          sol = min(sol, i * h + a * j + b * k);

  printf("%d\n", sol);
  return 0;
}
