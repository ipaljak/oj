#include <cstdio>

using namespace std;

int k;

inline void spoji(int l1, int h1, int l2, int h2, int v) {
    for (int i = l1; i <= h1; i += 2) printf("%d %d\n", i, i + 1);
    for (int i = l1; i <= h1; ++i) 
        for (int j = l2; j <= h2; ++j) printf("%d %d\n", i, j);
    for (int i = l2; i <= h2; ++i) printf("%d %d\n", i, v);
}

int main(void) {

    scanf("%d", &k);

    if (k % 2 == 0) {
        printf("NO\n"); 
        return 0;
    }

    printf("YES\n");
    printf("%d %d\n", 4 * k - 2, k * (4 * k - 2) / 2);
    
    spoji(1, k - 1, k, 2 * k - 2, 2 * k - 1);
    printf("%d %d\n", 2 * k - 1, 2 * k);
    spoji(3 * k, 4 * k - 2, 2 * k + 1, 3 * k - 1, 2 * k);

    return 0;

}
