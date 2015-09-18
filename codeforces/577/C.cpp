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

bool bio[1001];

int n;

vector <int> sol;

inline bool prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main(void) {

    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        if (!prime(i)) continue;
        int x = i;
        while (x <= n) {
            sol.push_back(x);
            x *= i;
        }
    }

    printf("%d\n", (int) sol.size());
    for (int i = 0; i < (int) sol.size(); ++i)
        printf("%d ", sol[i]);

    printf("\n");

    return 0;

}

