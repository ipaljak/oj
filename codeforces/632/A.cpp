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

int n, p;

int main(void) {

    scanf("%d%d", &n, &p);
    
    llint a = 0;
    for (int i = 0; i < n; ++i) {
        char s[25]; scanf("%s", s);
        if (strlen(s) > 4) a += 1LL << i;
    }

    llint m = 0;
    while (a > 0) {
        m += a * (p / 2LL);
        a /= 2;
    }

    printf("%lld\n", m);
    
    return 0;

}

