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

int main(void) {

    scanf("%d%d", &a, &b);
    printf("%d %d\n", min(a, b), (max(a, b) - min(a, b)) / 2);

    return 0;

}

