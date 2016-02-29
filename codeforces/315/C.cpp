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

int n, k;

int main(void) {

    scanf("%d%d", &n, &k);

    int _n = n, rank = 1, sol = 0;
    llint poz = 0LL;

    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        if (i != 0) {
            llint d = poz - (llint) (_n - rank) * x * (rank - 1);
            if (d < k) {
                ++sol; 
                --_n;
                printf("%d\n", i + 1);
                continue;
            }
        }
        poz += (llint) x * (rank - 1);  
        ++rank;
    }

    return 0;

}

