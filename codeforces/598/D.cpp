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

#define MAXN 1005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

bool bio[MAXN][MAXN];

char grid[MAXN][MAXN];

int R, S, Q, val;
int sol[MAXN][MAXN];

int dr[] = {1, 0, -1, 0};
int ds[] = {0, 1, 0, -1};

inline bool free(int r, int s) {
    return r >= 0 && r < R && s >= 0 && s < S && grid[r][s] == '.';
}

inline bool border(int r, int s) {
    return r >= 0 && r < R && s >= 0 && s < S && grid[r][s] == '*';
}

void dfs(int r, int s) {
    
    if (bio[r][s]) return;
    bio[r][s] = true;

    for (int i = 0; i < 4; ++i) {
        int _r = r + dr[i], _s = s + ds[i];
        if (free(_r, _s))  
            dfs(_r, _s);
        else
            ++val;
    }

}

void fill(int r, int s) {
    
    if (sol[r][s] != -1) return;
    sol[r][s] = val;

    for (int i = 0; i < 4; ++i) {
        int _r = r + dr[i], _s = s + ds[i];
        if (free(_r, _s))  
            fill(_r, _s);
    }
}

int main(void) {

    scanf("%d%d%d", &R, &S, &Q);
    
    for (int i = 0; i < R; ++i)
        scanf("%s", grid[i]);

    memset(sol, -1, sizeof sol);
    for (int i = 0; i < R; ++i) 
        for (int j = 0; j < S; ++j)
            if (free(i, j) && sol[i][j] == -1) {
                val = 0; dfs(i, j);
                fill(i, j);
            }

    for (int i = 0; i < Q; ++i) {
        int r, s; scanf("%d%d", &r, &s); --r; --s;
        printf("%d\n", sol[r][s]);
    }

    return 0;

}

