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

#define MAXM 1001

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

bool bio[MAXM], _bio[MAXM];

int n, m;

int main(void) {

    scanf("%d%d", &n, &m);

    if (n > m) {
        printf("YES\n");
        return 0;
    }

    bool check = false;
    int pref = 0;
    
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x); 
        memset(_bio, false, sizeof _bio);
        for (int j = 0; j < m; ++j) 
            if (bio[j]) _bio[(j + x) % m] = true;
        for (int j = 0; j < m; ++j)
            bio[j] |= _bio[j];
        bio[x % m] = true;
    }

    if (bio[0]) printf("YES\n"); else printf("NO\n");

    return 0;

}

