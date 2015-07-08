#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n, w;
int a[200010];

int main(void) {

    scanf("%d%d", &n, &w);
    for (int i = 0; i < 2*n; ++i) 
        scanf("%d", &a[i]);

    sort(a, a + 2*n);
    double x = min((double) a[0], (double) a[n] / 2);
    
    printf("%.6lf\n", min((double) 3 * n * x, (double) w));

    return 0;

}
