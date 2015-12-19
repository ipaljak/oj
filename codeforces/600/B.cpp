#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXN 200010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n, m;
int a[MAXN];

int main(void) {

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);

    sort(a, a + n);

    for (int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        int sol = (int) (upper_bound(a, a + n, x) - a);
        printf("%d ", sol);
    }

    printf("\n");

    return 0;

}

