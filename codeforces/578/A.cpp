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

int a, b;

const double inf = 1e9;

int main(void) {

    scanf("%d%d", &a, &b);

    int k1 = (a + b) / (2 * b), k2 = (a - b) / (2 * b);
   
    if (k1 <= 0 && k2 <= 0) {
        printf("-1\n");
        return 0;
    }

    double sol1 = inf, sol2 = inf;
    if (k1 > 0) sol1 = (double) (a + b) / (2 * k1);
    if (k2 > 0) sol2 = (double) (a - b) / (2 * k2);

    printf("%.10lf\n", min(sol1, sol2)); 

    return 0;

}

