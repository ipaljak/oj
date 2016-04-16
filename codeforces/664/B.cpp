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

int n; 

queue <int> pos_loc, neg_loc; 

bool check(int k, int sum) {
  if (k == 0) return sum == 0;
  if (sum <= 0) return false;
  if (k > sum || k * n < sum) return false;
  return true; 
}

int main(void) {

  int curr = 0;
  char s[2];

  scanf("%s", s);
  pos_loc.push(curr++);

  while (true) {
    scanf("%s", s);
    if (s[0] == '=') break;
    if (s[0] == '+')
      pos_loc.push(curr++);
    else
      neg_loc.push(curr++);
    scanf("%s", s);
  }

  scanf("%d", &n);

  int pos = -1, neg = -1;
  for (int i = 0; i <= pos_loc.size() * n; ++i) {
    if (check((int) pos_loc.size(), i) && check((int) neg_loc.size(), i - n)) {
      pos = i;
      neg = i - n;
      break;
    }
  }

  if (pos == -1) {
    printf("Impossible\n");
    return 0;
  }

  printf("Possible\n");

  int pos_cnt = (int) pos_loc.size(), neg_cnt = (int) neg_loc.size();
  bool first = true;

  while (!pos_loc.empty() || !neg_loc.empty()) {
   
    fflush(stdout);
    if (neg_loc.empty() || (!pos_loc.empty() && pos_loc.front() < neg_loc.front())) {
      
      if (!first) printf("+ ");
      int x = n;
      while (!check(pos_cnt - 1, pos - x)) --x;

      printf("%d ", x);
      --pos_cnt; pos -= x;

      pos_loc.pop();

    } else {
      
      printf("- ");
      
      int x = n;
      while (!check(neg_cnt - 1, neg - x)) --x;
      printf("%d ", x);
      --neg_cnt; neg -= x;

      neg_loc.pop();
    }

    first = false;
  }

  printf("= %d\n", n); 
    
  return 0;

}

