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

#define MAXN 200010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

const double eps = 1e-11;

int n;
double a[MAXN], dp_h[MAXN], dp_l[MAXN];

bool sgn(double x) {
    return x < eps;
}

double check(double x) {
    
    double h, l;
    dp_h[0] = dp_l[0] = l = h = a[0] - x;
    
    for (int i = 1; i < n; ++i) {
        dp_h[i] = max(dp_h[i - 1] + a[i] - x, a[i] - x);
        dp_l[i] = min(dp_l[i - 1] + a[i] - x, a[i] - x);
        h = max(h, dp_h[i]); l = min(l, dp_l[i]);
    }

    return max(abs(h), abs(l));

}

double ternary(double lo, double hi) {
    
    while (abs(hi - lo) > eps) {
        
        double left = lo + (hi - lo) / 3.0;
        double right = hi - (hi - lo) / 3.0;

        if (check(left) > check(right)) lo = left; else hi = right; 

    }
    
    return (lo + hi) / 2.0;

}

int main(void) {
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%lf", &a[i]);

    printf("%.10lf\n", check(ternary(-500000.0, 500000.0)));

    return 0;

}

