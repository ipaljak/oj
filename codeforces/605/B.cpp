#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXN 100010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

struct edge {
    
    bool inMST;
    int idx, val;

    edge() {}
    edge(int _idx, int _val, bool _inMST) {
        val = _val;
        idx = _idx;
        inMST = _inMST;
    }

    friend bool operator < (const edge &e1, const edge &e2) {
        if (e1.val == e2.val) return e1.inMST > e2.inMST;
        return e1.val < e2.val;
    }

};

int n, m, r = 1, s = 2;
int from[MAXN], to[MAXN];

edge E[MAXN];

void find_next() {
    if (s - r > 1)
        return;
    if (r < s) {
        ++r;
    } else {
        ++s;
        r = 1;
    } 
    find_next();
}

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        E[i] = edge(i, a, b);
    }

    sort(E, E + m); 

    int node = 1;
    for (int i = 0; i < m; ++i) {
        if (E[i].inMST) {
            from[E[i].idx] = node;
            to[E[i].idx] = ++node;
            continue;
        } else {
            find_next();
            if (r > node || s > node) {
                printf("-1\n");
                return 0;
            }
            from[E[i].idx] = r;
            to[E[i].idx] = s;
            if (r < s) { ++r; } else {++s; r = 1;}
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%d %d\n", from[i], to[i]);

    return 0;

}

