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

#define MAXN 100005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;
int niz[MAXN];

int main(void) {

    scanf("%d", &n);

    bool fail = false;
    int pivot = 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &niz[i]);
        if (i == 0) continue;
        fail |= niz[i] == niz[pivot];
        if (niz[i] < niz[pivot]) {
            pivot = i;
            fail = false;
        }
    }

    if (fail)
        printf("Still Rozdil\n");
    else
        printf("%d\n", pivot + 1);

    return 0;

}

