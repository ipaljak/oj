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

#define MAXN 2005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

char grid[MAXN][MAXN];

int R, S;
int deg[MAXN][MAXN];

int dr[] = {1, 0, -1, 0};
int ds[] = {0, 1, 0, -1};

queue <pii> Q;

inline bool empty(int r, int s) {
    return r >= 0 && r < R && s >= 0 && s < S && grid[r][s] == '.';
}

inline void connect(int r1, int s1, int r2, int s2) {
    if (r1 == r2) {
        if (s1 > s2) swap(s1, s2);
        grid[r1][s1] = '<';
        grid[r2][s2] = '>';
    } else {
        if (r1 > r2) swap(r1, r2);
        grid[r1][s1] = '^';
        grid[r2][s2] = 'v';
    }
}

inline void add_new(int r, int s) {
    for (int i = 0; i < 4; ++i) 
        if (empty(r + dr[i], s + ds[i])) 
            if (--deg[r + dr[i]][s + ds[i]] == 1) 
                Q.push(make_pair(r + dr[i], s + ds[i]));
}

int main(void) {

    scanf("%d%d", &R, &S);
    for (int i = 0; i < R; ++i) 
        scanf("%s", grid[i]);

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) { 
            if (!empty(i, j)) continue;
            for (int k = 0; k < 4; ++k) { 
                deg[i][j] += empty(i + dr[k], j + ds[k]);
            }
            if (deg[i][j] == 1) Q.push(make_pair(i, j));
        } 
    }

    while (!Q.empty()) {
        
        int r = Q.front().first, s = Q.front().second;
        Q.pop();

        if (deg[r][s] != 1) continue;

        for (int i = 0; i < 4; ++i) {

            int _r = r + dr[i], _s = s + ds[i];
            if (!empty(_r, _s)) continue;
        
            connect(r, s, _r, _s);

            add_new(r, s);
            add_new(_r, _s);

        }

    }
    
    for (int i = 0; i < R; ++i) 
        for (int j = 0; j < S; ++j) 
            if (empty(i, j)) {
                printf("Not unique\n");
                return 0;
            }        

    for (int i = 0; i < R; ++i) 
        printf("%s\n", grid[i]);    

    return 0;

}

