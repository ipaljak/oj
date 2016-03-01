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

#define MAXN 500010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

char s[MAXN];

int n;
int p[MAXN];

llint pref_A[MAXN], pref_B[MAXN];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &p[i]);    

    scanf("%s", s);

    for (int i = 0; i < n; ++i) {
        pref_A[i + 1] = pref_A[i];
        pref_B[i + 1] = pref_B[i];
        if (s[i] == 'A') 
            pref_A[i + 1] += (llint) p[i];
        else
            pref_B[i + 1] += (llint) p[i];
    }

    llint sol = 0;
    for (int i = 0; i <= n; ++i) {
        sol = max(sol, pref_A[i] + pref_B[n] - pref_B[i]);
        sol = max(sol, pref_B[n - i] + pref_A[n] - pref_A[n - i]);
    }

    printf("%lld\n", sol);

    return 0;

}

