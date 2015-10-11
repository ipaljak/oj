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

int n, k, sol;
int skill[MAXN], rem[MAXN];

int main(void) {

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &skill[i]); 
        sol += skill[i] / 10;
        rem[i] = 10 - (skill[i] % 10);
    }

    sort(rem, rem + n);

    for (int i = 0; i < n && rem[i] < 10; ++i) {
        if (rem[i] <= k) {
            ++sol;
            k -= rem[i];
        }
    }

    sol += k / 10;
    printf("%d\n", min(sol, 10 * n));

    return 0;

}

