#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

int k, n;

map <string, bool> bio;
map <string, vector<int>> vals;

vector <int> mids;

vector <string> v;
vector <pair<string, int>> palin;

inline bool cmp(const int &a, const int &b) {
  return a > b;
}

int main(void) {

  cin >> k >> n;
  for (int i = 0; i < k; ++i) {
    string s; int val;
    cin >> s >> val;
    v.push_back(s);
    vals[s].push_back(val);
  }

  for (string &s : v) {
    
    if (bio[s]) continue;
    
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    bio[s] = true;
    bio[rev] = true;

    sort(vals[s].begin(), vals[s].end(), cmp);
    sort(vals[rev].begin(), vals[rev].end(), cmp);

    if (s != rev) {
      for (int i = 0; i < min(vals[s].size(), vals[rev].size()); ++i) {
        if (vals[s][i] + vals[rev][i] > 0) {
          palin.emplace_back(s, vals[s][i]);
          palin.emplace_back(rev, vals[rev][i]);
        }
      }
    } else {
      for (int i = 0; i < min(vals[s].size(), vals[rev].size()); i += 2) {
        if (i + 1 >= vals[s].size() || vals[s][i] + vals[rev][i + 1] <= 0) {
          mids.emplace_back(vals[s][i]);
          break;
        }
        if (vals[s][i] + vals[rev][i + 1] > 0) {
          palin.emplace_back(s, vals[s][i]);
          palin.emplace_back(rev, vals[rev][i + 1]);
        }
      }
    }

  }

  mids.push_back(0);
  sort(mids.begin(), mids.end(), cmp);

  int sol = 0, mn = 0, mx = mids[0];
  for (auto &p : palin) {
//    TRACE(p.first _ p.second);
    if (p.second < 0 && p.first == string(p.first.rbegin(), p.first.rend())) 
      mn = min(mn, p.second);
    sol += p.second;
  }

  sol = max(sol - mn, sol + mx);
  printf("%d\n", sol);

  return 0;

}


