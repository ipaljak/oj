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

int n;

int main(void) {

    scanf("%d", &n);

    llint sum = 0, sol = 0;
    for (int i = 0; i < n; ++i) {
        llint x; scanf("%lld", &x);
        sol += abs(x - sum); 
        sum += x - sum;
    }

    printf("%lld\n", sol);

    return 0;

}

