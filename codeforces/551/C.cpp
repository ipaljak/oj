#include <algorithm>
#include <cstdio>

#define MAXN 100010

typedef long long llint;

using namespace std;

int n, m, dalj;
int pile[MAXN];

bool check(llint x) {
    
    int stud = 1;
    llint sec = x;
    
    for (int i = 0; i <= dalj; ++i) {
        
        if (sec == 0) {
            ++stud;
            sec = x - i - 1;
        } else {
            --sec;
        }
            
        int p = pile[i];
        while (p > 0) {
            int remove = (int) min((llint) p, sec);
            p -= remove;
            sec -= remove;
            if (sec == 0) {
                ++stud;
                sec = x - i - 1;
            }
        }

    }

    return stud - (sec == x - dalj - 1) <= m;
}
    
int main(void) {
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pile[i]);
        if (pile[i] != 0) dalj = i;
    }

    
    llint lo = (llint) dalj + 2, hi = 1000000000000000000LL, mid;
    while (lo < hi) {
        // printf("%lld %lld\n", lo, hi);
        mid = (lo + hi) / 2;
        if (check(mid)) hi = mid; else lo = mid + 1;
    }

    printf("%I64d\n", lo);

    return 0;

}
