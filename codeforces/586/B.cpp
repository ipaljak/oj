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

const int inf = 100000000;

int n;
int a[55], b[55], road[55];

int main(void) {

    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; ++i) 
        scanf("%d", &road[i]);    

    int sol = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            int tmp = 0;
            for (int k = n - 1; k > i; --k) tmp += b[k - 1];
            tmp += road[i];
            for (int k = i; k > 0; --k) tmp += a[k - 1];
            for (int k = 0; k < j; ++k) tmp += a[k];
            tmp += road[j];
            for (int k = j; k < n - 1; ++k) tmp += b[k];
            sol = min(sol, tmp);
        }
    }

    printf("%d\n", sol);

    return 0;

}

