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

#define MAXN 100005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int na, nb, k, m;
int a[MAXN], b[MAXN];

int main(void) {

    scanf("%d%d%d%d", &na, &nb, &k, &m);
    
    for (int i = 0; i < na; ++i) 
        scanf("%d", &a[i]);

    for (int i = 0; i < nb; ++i)
        scanf("%d", &b[i]);

    sort(a, a + na);
    sort(b, b + nb);

    if (a[k - 1] < b[nb - m]) 
        printf("YES\n");
    else
        printf("NO\n");

    return 0;

}

