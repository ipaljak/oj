#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int k, n, w;

int main(void) {

    scanf("%d%d%d", &k, &n, &w);
    printf("%d\n", max(k * w * (w + 1) / 2 - n, 0));

    return 0;

}
