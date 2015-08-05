#include <cstdio>
#include <set>

using namespace std;

int n, k, a, m;

set <int> s;

int ships(int len) {
    int ret = len / (a + 1);
    if (len - ret * (a + 1) == a) ++ret;
    return ret;
}

int main(void) {

    scanf("%d%d%d", &n, &k, &a);

    s.insert(0); s.insert(n + 1);
    int total = ships(n);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        
        int x; scanf("%d", &x);
        set <int> :: iterator itlo, ithi;
    
        ithi = itlo = s.upper_bound(x); --itlo;
        total -= ships(*ithi - *itlo - 1);
        total += ships(x - *itlo - 1) + ships(*ithi - x - 1);

        s.insert(x);

        if (total < k){ printf("%d\n", i + 1); return 0; }

    }

    printf("-1\n");

    return 0;

}
