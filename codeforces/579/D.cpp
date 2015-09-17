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

int n, k, x;
int niz[MAXN];

llint l[MAXN], r[MAXN];

int main(void) {

    scanf("%d%d%d", &n, &k, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &niz[i]);
        l[i + 1] = l[i] | niz[i];
    }

    for (int i = 0; i < n; ++i) 
        r[n - i - 1] = r[n - i] | niz[n - i - 1];
    
    llint h = 1LL;
    for (int i = 0; i < k; ++i) h *= (llint) x;

    llint sol = 0;
    
    for (int i = 0; i < n; ++i) {
        llint curr = (llint) niz[i] * h;
        sol = max(sol, l[i] | curr | r[i + 1]);
    }

    printf("%lld\n", sol);

    return 0;

}

