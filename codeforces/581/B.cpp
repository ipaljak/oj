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

#define MAXN 100010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;
int a[MAXN], sufmax[MAXN];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &a[i]);

    for (int i = n - 1; i >= 0; --i) 
        sufmax[i] = max(a[i], sufmax[i + 1]);

    for (int i = 0; i < n; ++i) 
        printf("%d ", max(0, sufmax[i + 1] - a[i] + 1));    

    printf("\n");

    return 0;

}

