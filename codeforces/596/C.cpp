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

#define MAXN 100005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;

int p_pos[MAXN], p_neg[MAXN];

vector <pii> sol;
vector <pii> pos[MAXN], neg[MAXN];

inline bool cmp(const pii &A, const pii &B) {
    return A.first < B.first;
}

inline void impossible() {
    printf("NO\n");
    exit(0);
}

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        if (x > y) 
            neg[x - y].push_back({x, y});
        else 
            pos[y - x].push_back({x, y});
    }

    for (int i = 0; i <= 100000; ++i) {
        if (!pos[i].empty()) sort(pos[i].begin(), pos[i].end(), cmp);
        if (!neg[i].empty()) sort(neg[i].begin(), neg[i].end(), cmp);
    }

    for (int i = 0; i < n; ++i) {
        int w; scanf("%d", &w);
        if (w < 0) {
            if (p_neg[-w] >= neg[-w].size()) impossible();
            sol.push_back(neg[-w][p_neg[-w]++]);
        } else {
            if (p_pos[w] >= pos[w].size()) impossible();
            sol.push_back(pos[w][p_pos[w]++]);
        }
    }

    for (int i = 0; i < (int) sol.size(); ++i) {
        if ((sol[i].first + 1) * (sol[i].second + 1) > i + 1) impossible();
    }

    printf("YES\n");
    for (int i = 0; i < (int) sol.size(); ++i) {
        printf("%d %d\n", sol[i].first, sol[i].second);
    }

    return 0;



}

