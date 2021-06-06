#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

template <class> struct is_container : false_type {};
template <class... Ts> struct is_container<vector<Ts...>> : true_type {};
template <class... Ts> struct is_container<map<Ts...>> : true_type {};
template <class... Ts> struct is_container<unordered_map<Ts...>> : true_type {};
template <class... Ts> struct is_container<list<Ts...>> : true_type {};
template <class... Ts> struct is_container<set<Ts...>> : true_type {};
template <class... Ts> struct is_container<unordered_set<Ts...>> : true_type {};
template <class T, class = typename enable_if<is_container<T>::value>::type>
ostream& operator << (ostream &o, T x) {
  int f = 1;
  o << "[";
  for (auto y : x) {
    o << (f ? "" : ", ") << y;
    f = 0;
  }
  return o << "]";
}
template<class T, class U>
ostream& operator<< (ostream &o, pair<T, U> x) {
  return o << "(" << x.first << ", " << x.second << ")";
}

typedef long long llint;

const int MOD = 1e9 + 7;
const int MAXN = 4000005;

int t, n, m;
int pow2[MAXN];

char row[2010];

inline int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

inline int mul(int a, int b) {
  return (llint)a * b % MOD;
}

inline void init() {
  pow2[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    pow2[i] = mul(2, pow2[i - 1]);
}

void solve() {
  scanf("%d%d", &n, &m);
  bool zero = false;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", row);
    for (int j = 0; j < m; ++j) {
      cnt += row[j] == '#';
      zero |= row[j] == '0';
    }
  }

  if (zero)
    printf("%d\n", pow2[cnt]);
  else
    printf("%d\n", add(pow2[cnt], -1));
}

int main(void) {
  init();
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
