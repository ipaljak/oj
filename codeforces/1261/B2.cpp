#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long llint;

const int MAXN = 2e5 + 10;

class Population {
  public:
    Population() {
      sz = 0;
      memset(loga, 0, sizeof loga);
    }

    void insert(int i) {
      ++sz;
      for (; i < 1 << 19; i += i & -i) ++loga[i];
    }

    int size() { return sz; }

    int kth_number(int k) {
      int sum = 0, sol = 0;
      for (int i = 18; i >= 0; --i) {
        if (sum + loga[sol + (1 << i)] < k) {
          sol |= 1 << i;
          sum += loga[sol];
        }
      }
      return sol + 1;
    }

  private:
    int sz;
    int loga[1 << 19];
} P;

struct Query {
  int k, pos, id;
  Query(int _k, int _pos, int _id) : k(_k), pos(_pos), id(_id) {}
  friend bool operator<(const Query &A, const Query &B) { return A.k < B.k; }
};

int n, m;

llint sol[MAXN];

vector<pair<llint, int>> a;
vector<Query> Q;

inline bool cmp(const pair<llint, int> &A, const pair<llint, int> &B) {
  if (A.first != B.first) return A.first > B.first;
  return A.second < B.second;
}

inline bool cmp_id(const pair<llint, int> &A, const pair<llint, int> &B) {
  return A.second < B.second;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    llint x; scanf("%lld", &x);
    a.emplace_back(x, i);
  }

  sort(a.begin(), a.end(), cmp);

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int k, pos;
    scanf("%d%d", &k, &pos);
    Q.emplace_back(k, pos, i);
  }

  sort(Q.begin(), Q.end());

  for (const auto &q : Q) {
    while (P.size() < q.k) {
      for (int i = P.size(); i < q.k; ++i) {
        //TRACE("UBACUJEM" _ a[i].second + 1);
        P.insert(a[i].second + 1);
      }
    }
    assert(P.size() == q.k);
    int ii = P.kth_number(q.pos);
    sol[q.id] = ii;
    //TRACE(q.id _ sol[q.id]);
    //printf("%lld\n", a[ii].first);
  }

  sort(a.begin(), a.end(), cmp_id);

  for (int i = 0; i < m; ++i) {
    //TRACE(sol[i]);
    printf("%lld\n", a[sol[i] - 1].first);
  }
  return 0;
}
