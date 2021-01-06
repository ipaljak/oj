#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

typedef long long llint;

bool rev = false;
int n, q, L, R;

llint loga[MAXN];

void inc(int i, llint x) {
  for (; i <= n + 5; i += i & -i) loga[i] += x;
}

llint sum(int lo, int hi) {
  llint ret = 0;
  for (; hi > 0; hi -= hi & -hi) ret += loga[hi];
  for (--lo; lo > 0; lo -= lo & -lo) ret -= loga[lo];
  return ret;
}

void fold(int p) {
  if (p <= (R - L + 1) / 2) {
    for (int i = 0; i < p; ++i) {
      if (!rev) {
        // loga[L + p + i] += loga[L + p - i - 1]
        llint val = sum(L + p - i - 1, L + p - i - 1);
        inc(L + p + i, val);
      } else {
        // loga[R - p - i] += loga[R - p + i + 1]
        llint val = sum(R - p + i + 1, R - p + i + 1);
        inc(R - p - i, val);
      }
    }
    if (!rev) L += p; else R -= p;
  } else {
    rev = !rev;
    fold((R - L + 1) - p);
  }
}

llint query(int l, int r) {
  if (rev) {
    l = (R - L + 1) - l;
    r = (R - L + 1) - r;
    swap(l, r);
    //printf("-- %d %d --\n", l, r);
  }
  return sum(L + l, L + r - 1);
}

int main(void) {
  scanf("%d%d", &n, &q);

  for (int i = 0; i < n; ++i) inc(i + 1, 1LL);

  L = 1; R = n;
  for (int i = 0; i < q; ++i) {
    //printf("%d %d\n", L, R);
    //for (int j = 0; j < n; ++j) {
      //printf("%lld ", sum(j + 1, j + 1));
    //}
    //printf("\n");
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int p; scanf("%d", &p);
      fold(p);
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(l, r));
    }
  }
  return 0;
}
