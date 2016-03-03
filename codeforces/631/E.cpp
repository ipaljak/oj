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

#define MAXN 200010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;
int a[MAXN], pos[2 * 1000005], mx[2*1000005], mn[2*1000005];

llint total;
llint psum[MAXN];

inline void init() {
    for (int i = 0; i <= 2000001; ++i) {
        mn[i] = 2000000;
    }
}

int main(void) {

    init(); 

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        total += (llint) (i + 1) * a[i];
        int el = a[i] + 1000000;
        mx[el] = i;
        mn[el] = min(mn[el], i);
    }

    for (int i = 0; i < n; ++i)
        psum[i + 1] = psum[i] + (llint) a[i];

    for (int i = 1; i <= 2000000; ++i) {
        mx[i] = max(mx[i], mx[i - 1]);
    }

    for (int i = 2000000; i >= 0; --i) {
        mn[i] = min(mn[i], mn[i + 1]);
    }

    llint change = 0LL;
    for (int i = 0; i < n; ++i) {
        
        int el = a[i] + 1000000;
        int hi = mx[el], lo = mn[el];

//        printf("%d %d\n", lo, hi);

        change = max(change, psum[i] - psum[lo] - (llint) (i - lo) * a[i]);
        change = max(change, (llint) (hi - i) * a[i] - (psum[hi + 1] - psum[i + 1]));

//        printf("-- %d %d\n", i, change);

    }

    printf("%lld\n", total + change);

    return 0;

}

