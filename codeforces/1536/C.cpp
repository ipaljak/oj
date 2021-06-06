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
const int MAXN = 5e5 + 10;

struct frac {
  int a, b;
  frac (int x, int y) {
    if (y == 0) {
      a = 1; b = 0;
    } else if (x == 0) {
      a = 0; b = 1;
    } else {
      int g = __gcd(x, y);
      a = x / g;
      b = y / g;
    }
  }
  friend bool operator < (const frac &A, const frac &B) {
    if (A.a == B.a) return A.b < B.b;
    return A.a < B.a;
  }
};

int t, n;
int sol[MAXN];

char s[MAXN];

map<frac, int> dp;

inline void init() {
  dp.clear();
}

void solve() {
  init();
  scanf("%d", &n);
  scanf("%s", s);
  int a = s[0] == 'D', b = s[0] == 'K';
  dp[frac(a, b)] = 1;
  sol[0] = 1;
  for (int i = 1; i < n; ++i) {
    a += s[i] == 'D';
    b += s[i] == 'K';
    auto f = frac(a, b);
    dp[f] += 1;
    sol[i] = dp[f];
  }

  for (int i = 0; i < n; ++i)
    printf("%d ", sol[i]);
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
