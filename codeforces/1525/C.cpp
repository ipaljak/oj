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
const int MAXN = 3e5 + 10;

struct Robot {
  bool dir;
  int x, id;
  Robot() {}
  Robot(int x, bool dir, int id): x(x), dir(dir), id(id) {}
  friend bool operator < (const Robot &A, const Robot &B) {
    return A.x < B.x;
  }
};

int t, n, m;
int x[MAXN], sol[MAXN];

vector<Robot> even, odd;

inline void init() {
  even.clear();
  odd.clear();
  for (int i = 0; i < n; ++i) sol[i] = -1;
}

int get_time(const Robot &A, const Robot &B) {
  if (A.dir && !B.dir) return abs(A.x - B.x) / 2;
  if (!A.dir && !B.dir) return min(A.x, B.x) + abs(A.x - B.x) / 2;
  if (A.dir && B.dir) return m - max(A.x, B.x) + abs(A.x - B.x) / 2;
  if (!A.dir && B.dir) {
    //if (A.x <= (m - B.x)) {
      //TRACE("bla");
      //TRACE(A.x _ B.x _ m);
      //return A.x + (m - (B.x + A.x)) + (B.x + A.x) / 2;
    //} else {
      //return (m - B.x) + (A.x - (m - B.x)) + (A.x - (m - B.x)) / 2;
    //}
    return min(A.x, B.x) + m - max(A.x, B.x) + abs(A.x - B.x) / 2;
  }
}

void find_collisions(const vector<Robot> &v) {
  stack<Robot> s;
  for (auto &p : v) {
    if (s.empty() || p.dir) {
      s.push(p);
      continue;
    }
    sol[s.top().id] = sol[p.id] = get_time(s.top(), p);
    s.pop();
  }
  while (s.size() > 1) {
    auto r1 = s.top(); s.pop();
    auto r2 = s.top(); s.pop();
    sol[r1.id] = sol[r2.id] = get_time(r2, r1);
  }
}

void solve() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 0; i < n; ++i)
    scanf("%d", &x[i]);
  for (int i = 0; i < n; ++i) {
    char s[2];
    scanf("%s", s);
    if (x[i] % 2 == 0)
      even.emplace_back(x[i], s[0] == 'R', i);
    else
      odd.emplace_back(x[i], s[0] == 'R', i);
  }

  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());

  find_collisions(even);
  find_collisions(odd);

  for (int i = 0; i < n; ++i)
    printf("%d ", sol[i]);
  printf("\n");
}

int main(void) {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
