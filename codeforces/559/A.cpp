#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int a, b, c, d, e, f;

int fun(int base, int l1, int l2, int r1, int r2) {

    int ret = base;
    int rast = min(l1, r1), pad = min(l2, r2) - 1;
   
    l1 -= rast; r1 -= rast;
    l2 -= pad; r2 -= pad;

    ret += base * rast + rast * (rast + 1) / 2;
    base += rast; ret += base * max(l1, r1);

    ret += base * pad - pad * (pad + 1) / 2;

   return ret; 

}

int main(void) {

    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    printf("%d\n", fun(a, b, c, f, e) + fun(d, c, b, e, f));

    return 0;

}
