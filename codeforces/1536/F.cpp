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
const int MAXN = 1e6 + 10;

int fact[MAXN];

inline int ceil(int a, int b) {
  return (a + b - 1) / b;
}

inline int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

inline int mul(int a, int b) {
  return (llint)a * b % MOD;
}

inline int mypow(int a, int b) {
  int ret = 1;
  while (b > 0) {
    if (b & 1)
      ret = mul(ret, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}

inline int inv(int x) {
  return mypow(x, MOD - 2);
}

inline int choose(int n, int k) {
  if (k < 0) return 0;
  return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

int n;

inline void init() {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i)
    fact[i] = mul(i, fact[i - 1]);
}

int main(void) {
  scanf("%d", &n);
  init();

  int sol = 0;
  for (int i = ceil(n, 2); i <= n; ++i) {
    if (i % 2 == 1) continue;
    sol = add(sol, mul(fact[i], mul(2, add(choose(i, n - i), choose(i - 1, n - i - 1)))));
  }

  printf("%d\n", sol);
  return 0;
}
