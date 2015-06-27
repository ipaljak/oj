#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define MAXN 200005

typedef long long llint;

using namespace std;

struct event {
    
    bool is_interval;
    int index;
    llint lo, hi;

    event() {}

    friend bool operator < (const event &A, const event &B) {
        if (A.lo == B.lo) return A.is_interval > B.is_interval;
        return A.lo < B.lo;
    }
    
};

struct interval {
    
    int index;
    llint lo, hi;
    
    interval() {}
    interval(int _index, llint _lo, llint _hi) {
        index = _index;
        lo = _lo;
        hi = _hi;
    }
    
    friend bool operator < (const interval &A, const interval &B) {
        return A.hi > B.hi;
    }
};

int n, m, e_cnt;
int sol[MAXN];

llint l[MAXN], r[MAXN];

event E[2 * MAXN]; 
priority_queue <interval> pq;

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &l[i], &r[i]);
    }

    for (int i = 1; i < n; ++i) {
        E[i - 1].lo = l[i] - r[i - 1];
        E[i - 1].hi = r[i] - l[i - 1];
        E[i - 1].index = i - 1;
        E[i - 1].is_interval = true;
    }

    e_cnt = n;

    for (int i = 0; i < m; ++i) {
        llint x; scanf("%I64d", &x);
        E[e_cnt].lo = x;
        E[e_cnt].is_interval = false;
        E[e_cnt++].index = i;
    }

    sort(E, E + e_cnt);

    for (int i = 0; i < e_cnt; ++i) {
        
        if (E[i].is_interval) {
            pq.push(interval(E[i].index, E[i].lo, E[i].hi));
        } else {
            while (!pq.empty() && E[i].lo > pq.top().hi) pq.pop();
            if (pq.empty()) continue;
            sol[pq.top().index] = E[i].index + 1;
            pq.pop();
        }

    }

    bool ok = true;
    for (int i = 0; i < n - 1; ++i) {
        if (sol[i] == 0) ok = false;
    }

    if (!ok) {
        printf("No\n");
    } else {
        printf("Yes\n");
        for (int i = 0; i < n - 1; ++i) printf("%d ", sol[i]);
        printf("\n");
    }

    return 0;

}
