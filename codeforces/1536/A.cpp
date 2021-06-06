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
const int MAXN = 105;

int t, n;
int a[MAXN];

inline void solve() {
  scanf("%d", &n);
  bool neg = false;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    neg |= a[i] < 0;
  }

  if (neg) {
    printf("No\n");
    return;
  }

  printf("Yes\n");
  printf("101\n");
  for (int i = 0; i <= 100; ++i)
    printf("%d ", i);
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
