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

bool row[55], col[55];

int n;

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n * n; ++i) {
        int r, c; scanf("%d%d", &r, &c);
        if (!row[r] && !col[c]) {
            row[r] = true;
            col[c] = true;
            printf("%d ", i + 1);
        }
    }

    printf("\n");

    return 0;

}

