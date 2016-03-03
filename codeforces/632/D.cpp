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
#include <unordered_map>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n, m;
int p[1000010], cnt[1000010];

unordered_map <int, vector<int> > mapa;

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) { 
        scanf("%d", &p[i]);
        mapa[p[i]].push_back(i + 1); 
    }

    for (auto it = mapa.begin(); it != mapa.end(); ++it) {
        int x = it -> first;
        int _x = x;
        while (_x <= m) {
            cnt[_x] += (it->second).size();
            _x += x;
        }
    }

    int pivot = 0;
    for (int i = 1; i <= m; ++i) {
        if (cnt[i] > cnt[pivot]) 
            pivot = i;
    }

    vector <int> sol;

    if (pivot == 0) {
        printf("1 0\n");
        return 0;
    }

    printf("%d ", pivot);
    for (int i = 0; i < n; ++i) {
        if (pivot % p[i] == 0) {
            sol.push_back(i + 1);
        }
    }

    printf("%d\n", (int) sol.size());
    for (int id : sol) printf("%d ", id);
    printf("\n");

    return 0;

}

