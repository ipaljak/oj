#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int N, a, b, c, sol;

vector <int> musk;
multiset <int> enemy;

void impossible() {
    puts("-1");
    exit(0);
}

void greedy(int hi, int lo) {

    while (!enemy.empty()) {
        
        auto it = enemy.end(); --it;
        if (*it < hi) break; else enemy.erase(it);

        it = enemy.lower_bound(lo);
        if (it != enemy.begin()) {
            --it;
            enemy.erase(it);
        }
        
        ++sol;
    } 

}

inline int clear_all(int x, int y) {
    if (x > y) swap(x, y);
    return y - x + max(0, 2 * x - y + 1) / 2;
}

int main(void) {

    scanf("%d%d%d%d", &N, &a, &b, &c);
    for (int i = 0; i < N; ++i) {
        int x; scanf("%d", &x);
        enemy.insert(x - 1);
    }

    musk = {a, b, c};
    sort(musk.begin(), musk.end());

    a = musk[0];
    b = musk[1];
    c = musk[2];

    auto it = enemy.end(); --it;
    if (*it >= a + b + c) 
        impossible();

    greedy(b + c, 0);
    greedy(a + c, a);   
    greedy(max(a + b, c), b);

    int x = 0, y = 0;
    for (int e : enemy) {
        x += e < a + b;
        y += e < c;
    }

    int best = clear_all(x, y);
    for (int i = 0; i < N && !enemy.empty(); ++i) {

        assert(max(x, y) == enemy.size());

        int curr = i + 1;

        for (int j = 0; j < 3 && !enemy.empty(); ++j) {
            auto it = enemy.lower_bound(musk[j]);
            if (it != enemy.begin()) {
                --it;
                x -= *it < a + b;
                y -= *it < c;
                enemy.erase(it);
            }
        }
            

        curr += clear_all(x, y);
        best = min(best, curr);
    }

    printf("%d\n", sol + best);

    return 0;

}

