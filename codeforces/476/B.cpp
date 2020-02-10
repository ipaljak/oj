#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int k;

string a, b;

bool check(int mask) {
  int ptr = 0, l = 0;
  for (char c : b) {
    l += (c == '+') - (c == '-');
    if (c == '?') {
      l += (mask & (1 << ptr)) != 0;
      l -= (mask & (1 << ptr)) == 0;
      ++ptr;
    }
  }
  return l == k;
}

int main(void) {
  cin >> a >> b;
  for (char c : a)
    k += (c == '+') - (c == '-');

  int cnt = 0;
  for (char c : b)
    cnt += c == '?';

  if (cnt == 0) {
    cout << check(0) << endl;
    return 0;
  }

  int x = 0, y = 1 << cnt;
  for (int mask = 0; mask < 1 << cnt; ++mask)
    x += check(mask);

  cout << std::setprecision(10) << (double) x / y << endl;
  return 0;
}
