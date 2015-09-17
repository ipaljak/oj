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

struct team {
    
    int a, b, s;

    team () {}

    team (int _a, int _b, int _s) {
        a = _a;
        b = _b;
        s = _s;
    }

    friend bool operator < (const team &A, const team &B) {
        return A.s > B.s;
    }

};

bool bio[1000];

int n;
int sol[1000];

vector <team> v;

int main(void) {

    scanf("%d", &n);
    for (int i = 1; i < 2 * n; ++i) {
        for (int j = 0; j < i; ++j) {
            int x; scanf("%d", &x);
            v.push_back(team(i + 1, j + 1, x));
        }
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < (int) v.size(); ++i) {
        if (!bio[v[i].a] && !bio[v[i].b]) {
            bio[v[i].a] = bio[v[i].b] = true;
            sol[v[i].a] = v[i].b;
            sol[v[i].b] = v[i].a;
        }
    }

    for (int i = 1; i <= 2 * n; ++i)
        printf("%d ", sol[i]);

    printf("\n");

    return 0;

}

