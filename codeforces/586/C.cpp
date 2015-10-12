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

#define MAXN 4005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;

llint v[MAXN], d[MAXN], p[MAXN];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%lld%lld%lld", &v[i], &d[i], &p[i]);    

    queue <int> q;

    for (int i = 0; i < n; ++i) {
        if (p[i] < 0) continue;
        q.push(i + 1);
        llint office = v[i], hall = 0;
        for (int j = i + 1; j < n; ++j) {
            if (p[j] < 0LL) continue;
            p[j] -= office + hall;
            if (p[j] < 0LL) hall += d[j];
            office = max(0LL, office - 1);
        } 
    }

    printf("%d\n", (int) q.size());
    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop();
    }

    printf("\n");
        
    return 0;

}

