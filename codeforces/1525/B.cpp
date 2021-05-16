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
    int n;
    scanf("%d", &n);
    vector<int> v;
    bool sorted = true;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      sorted &= x == (i + 1);
      v.push_back(x);
    }
    if (sorted) {
      printf("0\n");
      continue;
    }
    if (v[0] == 1 || v[n - 1] == n) {
      printf("1\n");
      continue;
    }
    if (v[0] == n && v[n - 1] == 1) {
      printf("3\n");
    } else {
      printf("2\n");
    }
  }
  return 0;
}
