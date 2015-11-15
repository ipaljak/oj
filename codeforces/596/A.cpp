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

int n;
int x[5], y[5];

int main(void) {
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }

    bool pass = false;
    int area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (x[i] != x[j] && y[i] != y[j]) {
                pass = true; 
                area = (max(x[i], x[j]) - min(x[i], x[j])) * (max(y[i], y[j]) - min(y[i], y[j]));
            }
        }
    }

    if (!pass)
        printf("-1\n");
    else
        printf("%d\n", area);

    return 0;

}

