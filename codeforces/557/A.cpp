#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int N;
int l[4], h[4];

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d", &l[i], &h[i]);
        h[i] -= l[i];
    }
    
    int sol1 = l[0], sol2 = l[1], sol3 = l[2];
    N -= sol1 + sol2 + sol3;

    sol1 += min(h[0], N); N -= sol1 - l[0];
    sol2 += min(h[1], N); N -= sol2 - l[1];
    sol3 += min(h[2], N); N -= sol3 - l[2];

    printf("%d %d %d\n", sol1, sol2, sol3);

    return 0;

}
