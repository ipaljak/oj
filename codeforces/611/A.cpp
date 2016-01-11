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

char dummy[5], query[10];

int n;

int main(void) {

    scanf("%d%s%s", &n, dummy, query);

    if (query[0] == 'w') {
        n %= 7;
        if (n < 5) printf("52\n"); else printf("53\n");
    } else {
        if (n < 30) 
            printf("12\n");
        else if (n < 31)
            printf("11\n");
        else
            printf("7\n");
    }

    return 0;

}

