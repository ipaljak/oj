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

#define MAXN 10010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

char s[MAXN];
char tmp[MAXN];

int m, l, r, k;

int main(void) {

    scanf("%s", s);
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        
        scanf("%d%d%d", &l, &r, &k); --l; --r;
        k %= r - l + 1;
        

        for (int j = 0; j < k; ++j)
            tmp[j] = s[r - k + j + 1];

        for (int j = k; j <= r; ++j)
            tmp[j] = s[l + j - k];

        for (int j = l; j <= r; ++j) 
            s[j] = tmp[j - l];

    }

    printf("%s\n", s);

    return 0;

}

