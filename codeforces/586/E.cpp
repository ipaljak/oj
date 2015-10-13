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
typedef pair<llint, llint> pii;

llint x, y;

llint gcd(llint a, llint b) {
    if (b == 0LL) return a;
    return gcd(b, a % b);
}

void find_node(llint x, llint y) {
    if (x == y) return; 
    if (x < y) {
        llint d = (y - 1) / x;
        printf("%lldB", d);
        find_node(x, y - d * x);
    } else {
        llint d = (x - 1) / y;
        printf("%lldA", d);
        find_node(x - d * y, y);
    }
}

int main(void) {

    scanf("%lld%lld", &x, &y);

    if (gcd(x, y) != 1LL) {
        printf("Impossible\n");
        return 0;
    }

    find_node(x, y);
    printf("\n");

    return 0;

}

