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

int a, b, x, y, z;

int main(void) {

    scanf("%d%d", &a, &b);
   
    for (int i = 1; i <= 6; ++i) {
        if (abs(i - a) < abs(i - b)) ++x;
        if (abs(i - a) == abs(i - b)) ++y;
        if (abs(i - a) > abs(i - b)) ++z;
    }

    printf("%d %d %d\n", x, y, z);

    return 0;

}

