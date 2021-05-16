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
const int MAXN = 5005;
const int INF = 5000 * 5000 + 10;

int n;
int a[MAXN];
int memo[MAXN][MAXN];

vector<int> v;

int dp(int i, int j) {
  if (memo[i][j] != -1) return memo[i][j];
  if (j == 0) return 0;
  if (i == n) return INF;
  if (a[i] == 1) return memo[i][j] = dp(i + 1, j);
  int ret = dp(i + 1, j);
  ret = min(ret, abs(i - v[v.size() - j]) + dp(i + 1, j - 1));
  return memo[i][j] = ret;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] == 1) v.emplace_back(i);
  }

  memset(memo, -1, sizeof memo);
  printf("%d\n", dp(0, (int)v.size()));
  return 0;
}
