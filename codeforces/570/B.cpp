#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;

int main(void) {

    scanf("%d%d", &n, &m);
    
    if (n == 1) {
        printf("1\n");
        return 0;
    }

    if (m - 1 >= n - m)
        printf("%d\n", m - 1);
    else 
        printf("%d\n", m + 1);

    return 0;

}
