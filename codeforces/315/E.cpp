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

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

const int mod = 1000000007;

int n;
int loga[1000010];

inline int mul(int x, int y) {
    return (llint) x * y % mod; 
}

inline int sum(int lo, int hi) {
    int ret = 0; 
    for (; hi > 0; hi -= hi & -hi) {
        ret += loga[hi]; 
        ret %= mod;
    }
    for (--lo; lo > 0; lo -= lo & -lo) {
        ret -= loga[lo];
        if (ret < 0) ret += mod;
    }
    return ret;
}

inline void set(int i, int val) {
    val -= sum(i, i); if (val < 0) val += mod;
    for (; i <= 1000000; i += i & -i) {
        loga[i] += val;
        loga[i] %= mod; 
    }
}

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        int s = mul(sum(1, x), x); 
        s += x; s %= mod;
        set(x, s); 
    }

    printf("%d\n", sum(1, 1000000));
    return 0;

}

