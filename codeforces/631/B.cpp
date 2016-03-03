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

#define MAXN 5010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int r, s, k; 
int time_r[MAXN], time_s[MAXN], color_r[MAXN], color_s[MAXN];

int main(void) {

    scanf("%d%d%d", &r, &s, &k);
    for (int i = 0; i < k; ++i) {
        int t, a, b; scanf("%d%d%d", &t, &a, &b); --a;
        if (t == 1) {
            time_r[a] = i + 1;
            color_r[a] = b;
        } else {
            time_s[a] = i + 1;
            color_s[a] = b;
        }
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            if (time_r[i] > time_s[j])
                printf("%d ", color_r[i]);
            else
                printf("%d ", color_s[j]);
        }
        printf("\n");
    }

    return 0;

}

