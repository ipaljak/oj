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

#define MAXN 1001

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n; 
int a[MAXN], b[MAXN];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &b[i]);    

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        int ora = 0, orb = 0;
        for (int j = i; j < n; ++j) {
            ora |= a[j];
            orb |= b[j];
            sol = max(sol, ora + orb);
        }
    }

    printf("%d\n", sol);

    return 0;

}

