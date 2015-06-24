#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

typedef long long llint;

using namespace std;

int n;

llint k;
llint fib[55];

vector <int> sol;

int main(void) {

    scanf("%d%I64d", &n, &k);

    fib[1] = fib[0] = 1;
    for (int i = 1; i <= 51; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    for (int i = 0; i < n; ++i) {
        if (fib[n - i - 1] >= k) { 
            printf("%d ", i + 1);
        } else {
            printf("%d %d ", i + 2, i + 1);
            k -= fib[n - i - 1]; ++i;
        }
    }

    printf("\n");
    return 0;
    
}
