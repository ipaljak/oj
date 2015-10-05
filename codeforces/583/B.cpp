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
int a[1000];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);    

    int curr = 0, sol = -1;
    while (curr < n) {
        ++sol;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= curr) {
                a[i] = 2 * n;
                ++curr;
            }
        }
        if (curr == n) break;
        ++sol;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] <= curr) {
                a[i] = 2 * n;
                ++curr;
            }
        }
    }

    printf("%d\n", sol);

    return 0;

}

