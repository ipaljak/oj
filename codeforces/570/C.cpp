#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>

#define MAXN 300010

using namespace std;

struct interval {
    
    int l, r;

    interval() {}
    interval(int _l, int _r) {
        l = _l;
        r = _r;
    }

    friend bool operator < (const interval &A, const interval &B) {
        return A.l < B.l;
    }

};

char s[MAXN];

int n, m, sol;

set <interval> S;

void find_initials() {

    bool points = false;
    int l;

    for (int i = 0; i < n; ++i) {
        if (!points && s[i] == '.') {
            points = true;
            l = i;
        }
        if (points && s[i] != '.') {
            points = false;
            S.insert(interval(l, i - 1));
            sol += i - 1 - l;
        }
    }

    if (points) {
        S.insert(interval(l, n - 1));
        sol += n - 1 - l;
    }

}

int main(void) {

    scanf("%d%d", &n, &m);
    scanf("%s", s);

    S.insert(interval(-1, -1));
    S.insert(interval(n, n));
   
    find_initials();

    for (int i = 0; i < m; ++i) {
        
        int idx; char a[2]; 
        scanf("%d%s", &idx, a); --idx;
        
        if ((s[idx] == '.' && a[0] == '.') || (s[idx] != '.' && a[0] != '.')) {
            printf("%d\n", sol); 
            continue;
        }

        set <interval> :: iterator hi = S.upper_bound(interval(idx, idx)), lo = hi; --lo;

        if (a[0] != '.') {
            
            interval i = *lo; 
            S.erase(lo);
   
            if (i.r - i.l >= 1) {
                if (i.l == idx || i.r == idx) {
                    --sol;   
                } else {
                    sol -= 2;
                }
            } 

            interval i1 = interval(i.l, idx - 1), i2 = interval(idx + 1, i.r);
            
            if (i1.l <= i1.r) S.insert(i1);
            if (i2.l <= i2.r) S.insert(i2);

        } else {
            
            interval l = *lo, r = *hi;

            if (idx > 0 && idx < n - 1 && s[idx - 1] == s[idx + 1] && s[idx - 1] == '.') {
                S.erase(lo);
                S.erase(hi);
                sol += 2;
                S.insert(interval(l.l, r.r));
            } else if (idx > 0 && s[idx - 1] == '.') {
                S.erase(lo);
                ++sol;
                S.insert(interval(l.l, l.r + 1));
            } else if (idx < n - 1 && s[idx + 1] == '.') {
                S.erase(hi);
                ++sol;
                S.insert(interval(r.l - 1, r.r));
            } else {
                S.insert(interval(idx, idx));
            }

        }

        //for (set <interval> :: iterator it = S.begin(); it != S.end(); ++it) printf("%d %d\n", it -> l, it -> r);

        s[idx] = a[0];
        printf("%d\n", sol);

    }

    return 0;

}
