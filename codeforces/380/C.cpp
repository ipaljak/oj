#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;

struct Node {
  int a, b, c;
  Node() {}
  Node(int a, int b, int c) : a(a), b(b), c(c) {}
};

int n, m, offset;
char s[MAXN];

vector<Node> T;

Node merge(const Node &l, const Node &r) {
  int x = min(l.b, r.c);
  return Node(l.a + r.a + x, l.b + r.b - x, l.c + r.c - x);
}

void update(int i, Node x) {
  i += offset;
  T[i] = x;
  i /= 2;
  for (; i > 0; i /= 2) T[i] = merge(T[2 * i], T[2 * i + 1]);
}

Node query(int i, int from, int to, int lo, int hi) {
  if (from >= lo && to <= hi) return T[i];
  if (to <= lo || hi <= from) return Node(0, 0, 0);
  Node l = query(2 * i, from, (from + to) / 2, lo, hi);
  Node r = query(2 * i + 1, (from + to) / 2, to, lo, hi);
  return merge(l, r);
}

int main(void) {
  scanf("%s", s);
  n = strlen(s);

  for (offset = 1; offset <= n; offset *= 2);
  T.resize(2 * offset);

  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      update(i, Node(0, 1, 0));
    else
      update(i, Node(0, 0, 1));
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r); --l;
    printf("%d\n", 2 * query(1, 0, offset, l, r).a);
  }

  return 0;
}
