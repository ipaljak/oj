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

int maxbit = 0;

llint s, x;
llint memo[3][64];

llint dp(bool carry, int pos) {
    
    llint ret = 0;

    if (pos > maxbit) 
        return memo[carry][pos] = !carry;
  
    if (memo[carry][pos] != -1)
        return memo[carry][pos];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (i != j && (x & (1LL << pos)) == 0) continue;
            if (i == j && (x & (1LL << pos)) != 0) continue;
            if ((i + j + carry) % 2 == 0 && (s & (1LL << pos)) != 0) continue;
            if ((i + j + carry) % 2 != 0 && (s & (1LL << pos)) == 0) continue;
            ret += (llint) dp((i + j + carry) > 1, pos + 1);
        }
    }

    return memo[carry][pos] = ret; 

}   

int main(void) {

    scanf("%lld%lld", &s, &x);

    for (int i = 0; i < 63; ++i)
        if (((1LL << i) & s) != 0 || ((1LL << i) & x) != 0)
            maxbit = i;

    memset(memo, -1, sizeof memo);
    printf("%lld\n", dp(0, 0) - 2LL * (s == x));

    return 0;

}

