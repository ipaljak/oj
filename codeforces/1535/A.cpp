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

int t;

int main(void) {
  scanf("%d", &t);
  while (t--) {
    int a[5], b[5];
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    sort(b, b + 4);
    if ((min(a[0], a[1]) == b[2] && max(a[0], a[1]) == b[3]) ||
        (min(a[2], a[3]) == b[2] && max(a[2], a[3]) == b[3]))
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
