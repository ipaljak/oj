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

int a, b;

string d;
string sol; 

int main(void) {

  scanf("%d.", &a);

  while (true) {
    char c; scanf("%c", &c); 
    if (c == 'e') break;
    d.push_back(c); 
  }

  scanf("%d", &b);
  sol.push_back('0' + a);

  if (d.size() == 1 && d[0] == '0') {
    printf("%d", a);
    while (b--) printf("0");
    return 0;
  }

  for (int i = 0; i < min(b, (int) d.size()); ++i) 
    sol.push_back(d[i]);

  if (b >= d.size()) {
    b -= (int) d.size();
    while (b--) sol += "0";
  } else {
    sol += ".";
    for (int i = b; i < d.size(); ++i)
      sol.push_back(d[i]);
  }

  bool print = false;
  for (int i = 0; i < (int) sol.size(); ++i) {
    if (print) {
      printf("%c", sol[i]);
      continue;
    } else {
      if (sol[i] == '.') {
        print = true;
        printf("0.");
        continue;
      }
      if (sol[i] != '0') {
        print = true;
        printf("%c", sol[i]);
      }
    }
  }

  return 0;

}

