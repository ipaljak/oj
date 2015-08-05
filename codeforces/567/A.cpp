#include <algorithm>
#include <cstdio>

#define MAXN 100005

using namespace std;

int n;
int x[MAXN], pref[MAXN];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
        if (i != 0) pref[i] = pref[i - 1] + (x[i] - x[i - 1]);
    }

    for (int i = 0; i < n; ++i) {
        if (i == 0){ printf("%d %d\n", x[1] - x[0], pref[n - 1]); continue; }
        if (i == n - 1){ printf("%d %d\n", x[i] - x[i - 1], pref[n - 1]); continue; }
        printf("%d %d\n", min(x[i] - x[i - 1], x[i + 1] - x[i]), max(pref[i], pref[n - 1] - pref[i])); 
    }

    return 0;

}
