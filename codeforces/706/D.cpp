#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unordered_map>
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

struct node {
    
  int size;
  node *zero, *one;

  node () {
    size = 0;
    zero = one = NULL;
  }

};

node *trie; 

int q;
unordered_map <int, int> cnt; 

void insert(node *root, int num, int bit) {

  (*root).size++;
  if (bit == -1) return;

  if ((num & (1 << bit)) != 0) {
    if (root -> one == NULL) root -> one = new node();
    insert(root -> one, num, bit - 1);
  } else {
    if (root -> zero == NULL) root -> zero = new node();
    insert(root -> zero, num, bit - 1);
  }

}

void remove(node *root, int num, int bit) {

  if (bit == -1) return;

  (*root).size--;

  if ((num & (1 << bit)) != 0) {
    if ((*(root -> one)).size == 1) {
      root -> one = NULL;
      return;
    }
    remove(root -> one, num, bit - 1);
  } else {
    if ((*(root -> zero)).size == 1) {
      root -> zero = NULL;
      return;
    }
    remove(root -> zero, num, bit - 1);
  }

}

int query(node *root, int num, int bit) {
    
  if (root == NULL) return 0;
  
  int ret = 0;
  if ((num & (1 << bit)) != 0) {
    if (root -> zero != NULL)
      return (1 << bit) + query(root -> zero, num, bit - 1);
    if (root -> one != NULL)
      return query(root -> one, num, bit - 1);
  } else {
    if (root -> one != NULL)
      return (1 << bit) + query(root -> one, num, bit - 1);
    if (root -> zero != NULL)
      return query(root -> zero, num, bit - 1);
  }
  
  return ret;

}


int main(void) {

  trie = new node();

  insert(trie, 0, 30);
  cnt[0] = 1;

  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
   
    char s[2]; int x;
    scanf("%s%d", s, &x);

    if (s[0] == '+') {
      ++cnt[x];
      if (cnt[x] == 1) {
        insert(trie, x, 30);
      }
    }

    if (s[0] == '-') {
      --cnt[x];
      if (cnt[x] == 0) {
        remove(trie, x, 30);
      }
    }

    if (s[0] == '?') {
      printf("%d\n", query(trie, x, 30));
    }

  }
    
  return 0;

}

