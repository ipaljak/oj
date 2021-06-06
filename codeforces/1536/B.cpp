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
const int MAXN = 1001;

int t, n;
int ways[15];

string sol;

char s[MAXN];

void init() {
  ways[1] = 26;
  for (int i = 2; i <= 10; ++i)
    ways[i] = ways[i - 1] * 26;
}

void mex(int l, string curr, const set<string> &S) {
  if (sol.size() != 0) return;
  if (l == 0) {
    if (S.find(curr) == S.end()) sol = curr;
    return;
  }
  for (char c = 'a'; c <= 'z'; ++c) {
    curr.push_back(c);
    mex(l - 1, curr, S);
    curr.pop_back();
  }
}

void solve() {
  scanf("%d", &n);
  scanf("%s", s);

  sol = "";
  for (int l = 1; l <= 10; ++l) {
    set<string> S;
    for (int i = 0; i + l - 1 < n; ++i) {
      string curr = "";
      for (int j = 0; j < l; ++j) curr.push_back(s[i + j]);
      S.insert(curr);
    }
    if (S.size() == ways[l]) continue;
    mex(l, "", S);
    //TRACE(sol);
    for (char c : sol) printf("%c", c);
    printf("\n");
    return;
  }
}

int main(void) {
  init();
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
