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

const llint mod = 1000000007;

int n;

llint _pow(llint b, int e) {
    llint ret = 1;
    while (e) {
        if (e & 1) {ret *= b; ret %= mod;}
        e >>= 1; 
        b = b * b; b %= mod;
    }
    return ret;
}

int main(void) {

    scanf("%d", &n);
    
    printf("%lld\n", (_pow(27LL, n) - _pow(7, n) + 2 * mod) % mod);

    return 0;

}

