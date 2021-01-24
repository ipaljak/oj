#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

int n, m, k;
char s[MAXN], t[MAXN];

void fft(vector<complex<double>> &a, bool inv) {
  int n = (int)a.size();
  if (n == 1) return;

  vector<complex<double>> even, odd;
  for (int i = 0; i < n; i += 2) {
    even.emplace_back(a[i]);
    odd.emplace_back(a[i + 1]);
  }

  fft(even, inv);
  fft(odd, inv);

  double theta = 2 * M_PI / n;
  if (inv) theta = -theta;
  complex<double> p(1), dp(cos(theta), sin(theta));
  for (int i = 0; i < n / 2; ++i) {
    a[i] = even[i] + p * odd[i];
    a[i + n / 2] = even[i] - p * odd[i];
    p *= dp;
    if (inv) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
  }
}

void iter_fft(vector<complex<double>> &a, bool inv) {
  int n = (int)a.size();

  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;

    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * M_PI / len;
    if (inv) ang = -ang;
    complex<double> wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int j = 0; j < len / 2; j++) {
        complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }

  if (inv) {
    for (complex<double> &x : a) x /= n;
  }
}

vector<int> mult(vector<int> &a, vector<int> &b) {
  vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int sz = 1;
  while (sz < (int)a.size() + (int)b.size()) sz <<= 1;
  fa.resize(sz);
  fb.resize(sz);

  iter_fft(fa, false);
  iter_fft(fb, false);

  for (int i = 0; i < sz; ++i)
    fa[i] *= fb[i];

  iter_fft(fa, true);

  vector<int> ret;
  for (int i = m - 1; i < sz; ++i)
    ret.emplace_back(round(fa[i].real()));

  return ret;
}

vector<int> match(char c) {
  queue<int> pos;
  for (int i = 0; i < n; ++i)
    if (s[i] == c) pos.push(i);

  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    while (!pos.empty() && i > pos.front() + k) pos.pop();
    a.emplace_back(!pos.empty() && abs(i - pos.front()) <= k);
  }

  for (int i = 0; i < m; ++i)
    b.emplace_back(t[m - i - 1] == c);

  return mult(a, b);
}

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  scanf("%s%s", s, t);

  auto ma = match('A');
  auto mc = match('C');
  auto mt = match('T');
  auto mg = match('G');

  int sol = 0;
  for (int i = 0; i < n - m + 1; ++i)
    sol += (ma[i] + mc[i] + mt[i] + mg[i]) == m;

  printf("%d\n", sol);
  return 0;
}
