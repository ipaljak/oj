#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int ceil(int a, int b) {
  return (a + b - 1) / b;
}

llint f(int x, int y) {
  int a = x / y + 1;
  int b = x / y;
  int k = x % y;
  assert(k * a + (y - k) * b == x);
  return (llint) k * a * a + (llint) (y - k) * b * b;
}

struct Carrot {
  int x, y;
  Carrot(int x, int y): x(x), y(y) {}
  friend bool operator < (const Carrot &A, const Carrot &B) {
    return f(A.x, A.y) - f(A.x, A.y + 1) < f(B.x, B.y) - f(B.x, B.y + 1);
  }
};

int n, k;
int a[MAXN];

priority_queue<Carrot> pq;

int main(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pq.push(Carrot(a[i], 1));
  }

  for (int i = 0; i < k - n; ++i) {
    auto c = pq.top(); pq.pop();
    c.y++;
    pq.push(c);
  }

  llint sol = 0;
  while (!pq.empty()) {
    sol += f(pq.top().x, pq.top().y);
    pq.pop();
  }

  printf("%lld\n", sol);
  return 0;
}
