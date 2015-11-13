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

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int t;

llint n;

void solve() {
    
    scanf("%lld", &n);

    llint sol = n * (n + 1) / 2;
    llint maxpow;

    for (maxpow = 1; maxpow <= n; maxpow *= 2);
    sol -= 2 * (maxpow - 1);

    printf("%lld\n", sol);

}

int main(void) {

    scanf("%d", &t);
    while (t--) solve();

    return 0;

}

