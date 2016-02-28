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

int n;
int A[MAXN], B[MAXN], next_A[MAXN], next_B[MAXN];

int main(void) {

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < n; ++i) {
        if (A[i] != 0) {
            if (A[(i + 1) % n] != 0)
                next_A[A[i]] = A[(i + 1) % n];
            else
                next_A[A[i]] = A[(i + 2) % n];
        } 
        if (B[i] != 0) {
            if (B[(i + 1) % n] != 0)
                next_B[B[i]] = B[(i + 1) % n];
            else
                next_B[B[i]] = B[(i + 2) % n];
        } 
    }

    bool ok = true;
    for (int i = 1; i <= n; ++i)
        ok &= next_B[i] == next_A[i];

    if (ok)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;

}

