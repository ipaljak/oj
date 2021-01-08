#include <bits/stdc++.h>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define _ << " " <<

typedef long long llint;

const int MOD = 1e9 + 7;

struct Node {
  Node *a, *b, *c;
  Node() { a = b = c = nullptr; }
};

int n, m;
Node trie;

void insert(Node *node, const string &s, int i) {
  if (i == s.size()) return;
  if (s[i] == 'a') {
    if (!node->a) node->a = new Node();
    insert(node->a, s, i + 1);
  }
  if (s[i] == 'b') {
    if (!node->b) node->b = new Node();
    insert(node->b, s, i + 1);
  }
  if (s[i] == 'c') {
    if (!node->c) node->c = new Node();
    insert(node->c, s, i + 1);
  }
}

bool query(Node *node, const string &s, int i, bool flag) {
  if (i == s.size()) return flag;
  if (!node) return false;
  bool ret = false;
  if (s[i] == 'a') {
    if (node->a) ret |= query(node->a, s, i + 1, flag);
    if (!flag && i < s.size() - 1)
      ret |= query(node->b, s, i + 1, true) || query(node->c, s, i + 1, true);
  }
  if (s[i] == 'b') {
    if (node->b) ret |= query(node->b, s, i + 1, flag);
    if (!flag && i < s.size() - 1)
      ret |= query(node->a, s, i + 1, true) || query(node->c, s, i + 1, true);
  }
  if (s[i] == 'c') {
    if (node->c) ret |= query(node->c, s, i + 1, flag);
    if (!flag && i < s.size() - 1)
      ret |= query(node->a, s, i + 1, true) || query(node->b, s, i + 1, true);
  }
  return ret;
}

int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    s += "abcbcabba";
    insert(&trie, s, 0);
  }

  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    s += "abcbcabba";
    if (query(&trie, s, 0, false))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
