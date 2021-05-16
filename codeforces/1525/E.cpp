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

const int MOD = 998244353;
const int MAXN = 25;
const int MAXM = 5e4 + 10;

int n, m;
int fact[MAXN];
int d[MAXN][MAXM];

inline int add(int a, int b) {
  if (a + b >= MOD) return a + b - MOD;
  if (a + b < 0) return a + b + MOD;
  return a + b;
}

inline int mul(int a, int b) {
  return (llint) a * b % MOD;
}

inline int mypow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) {
      ret = mul(ret, a);
      --b;
    }
    a = mul(a, a);
    b /= 2;
  }
  return ret;
}

inline int inv(int x) {
  return mypow(x, MOD - 2);
}

inline void init() {
  fact[0] = 1;
  for (int i = 1; i <= n; ++i)
    fact[i] = mul(i, fact[i - 1]);
}

int main(void) {
  scanf("%d%d", &n, &m); init();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", &d[i][j]);

  int sol = 0;
  for (int i = 0; i < m; ++i) {
    vector<int> v;
    for (int j = 0; j < n; ++j)
      v.push_back(d[j][i]);
    sort(v.begin(), v.end());
    //TRACE(i _ v);
    int curr = 1, taken = 0;
    for (int x : v) {
      if (x < taken) {
        curr = 0;
        break;
      }
      curr = mul(curr, (x - taken - 1));
      ++taken;
    }
    //TRACE(curr);
    sol = add(sol, curr);
  }

  //TRACE(sol);
  sol = add(mul(fact[n], m), -sol);
  sol = mul(sol, inv(fact[n]));
  printf("%d\n", sol);
  return 0;
}
