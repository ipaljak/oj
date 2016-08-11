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

int n, q;

vector <int> x; 

int main(void) {

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a; scanf("%d", &a);
    x.push_back(a);
  } 

  sort(x.begin(), x.end());

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int k; scanf("%d", &k);
    int sol = (int) (upper_bound(x.begin(), x.end(), k) - x.begin());
    printf("%d\n", sol);
  }


  return 0;

}

