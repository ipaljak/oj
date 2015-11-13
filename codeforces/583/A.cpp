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

#define MAXN 55

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

bool bio_a[MAXN], bio_b[MAXN];

int n;

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n * n; ++i) {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        if (!bio_a[a] && !bio_b[b]) {
            printf("%d ", i + 1);
            bio_a[a] = bio_b[b] = true;
        }
    }

    printf("\n");

    return 0;

}

