#include <algorithm>
#include <cstdio>
#include <map>

#define MAXN 200010

typedef long long llint;

using namespace std;

struct num {
    
    int ind, compressed;
    llint val;

    num () {}
    num (int _ind, llint _val) {
        ind = _ind;
        val = _val;
    }

    friend bool operator < (const num &A, const num &B) {
        return A.val < B.val;
    }
   
};

int n;
int cnt_left[MAXN], cnt_right[MAXN];

llint k;

map <llint, int> mapa;
num a[MAXN];

inline bool cmp_ind(const num &A, const num &B) {
    return A.ind < B.ind;
}

inline void compress() {
    
    sort(a, a + n);

    int c = 0; a[0].compressed = c;
    for (int i = 1; i < n; ++i) {
        c += a[i].val != a[i - 1].val;
        mapa[a[i].val] = a[i].compressed = c;
    }

    sort(a, a + n, cmp_ind);

}

int main(void) {

    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i].val);
        a[i].ind = i;
    }

    compress();
    for (int i = 0; i < n; ++i)
        ++cnt_right[a[i].compressed];

    llint sol = 0;
    for (int i = 0; i < n; ++i) {
        --cnt_right[mapa[a[i].val]];
        if (a[i].val % k == 0 && mapa.find(a[i].val / k) != mapa.end() && mapa.find(a[i].val * k) != mapa.end()) {
            sol += (llint) cnt_left[mapa[a[i].val / k]] * cnt_right[mapa[a[i].val * k]];
        }
        ++cnt_left[mapa[a[i].val]];
    }

    printf("%I64d\n", sol);

    return 0;

}
