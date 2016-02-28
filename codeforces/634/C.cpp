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

int n, k, a, b, q;
int order[MAXN];

llint pref_A[MAXN], pref_B[MAXN];

vector <int> v;

llint sum(int lo, int hi, llint *loga) {
    llint ret = 0LL; 
    for (; hi > 0; hi -= hi & -hi) ret += loga[hi];
    for (--lo; lo > 0; lo -= lo & -lo) ret -= loga[lo];
    return ret;
}

void set(int i, llint val, llint *loga) {
    val -= sum(i, i, loga);
    for (; i <= n; i += i & -i) loga[i] += val;
}
    
int main(void) {

    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);

    for (int i = 0; i < q; ++i) {
        int t, d; scanf("%d%d", &t, &d);
        if (t == 2) {
            printf("%lld\n", sum(0, d - 1, pref_B) + sum(d + k, n, pref_A));
            continue;
        }
        int x; scanf("%d", &x);
        order[d] += x;
        set(d, min(a, order[d]), pref_A);
        set(d, min(b, order[d]), pref_B);
    }

//    for (int i = 1; i <= n; ++i) {
//        pref_A[i] = pref_A[i - 1] + (llint) min(a, order[i]);
//        pref_B[i] = pref_B[i - 1] + (llint) min(b, order[i]);
//    }
//
//    for (int p : v) {
//        printf("%lld\n", pref_B[p - 1] + pref_A[n] - pref_A[p + k - 1]);
//    }
//    
    return 0;

}

