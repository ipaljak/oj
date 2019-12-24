#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

int ask(const string &s) {
  int ret = 0;
  cout << s << "\n";
  cout.flush();
  cin >> ret;
  if (ret == 0) exit(0);
  return ret;
}

int main(void) {
  int n = ask("a");
  string all_b = "";
  for (int i = 0; i < n; ++i) all_b.push_back('b');
  int k = ask(all_b);

  int B = n + 1 - k;
  ++n;
  int A = n - B;

  all_b.push_back('b');
  for (int i = 0; i < n; ++i) {
    all_b[i] = 'a';
    int curr = ask(all_b);
    assert(abs(curr - A) == 1);
    if (curr < A) {
      --A;
    } else {
      all_b[i] = 'b';
    }
  }

  assert(false);
  return 0;
}
