#include <cstdio>

#define MAXN 100001

using namespace std;

int n, div;
int a[MAXN];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i != 0) div = gcd(div, a[i]); else div = a[i];
    }

    for (int i = 0; i < n; ++i) {

        a[i] /= div;
    
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
        
        if (a[i] != 1) {
            printf("No\n");
            return 0;
        }

    }

    printf("Yes\n");

    return 0;

}
