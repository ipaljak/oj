#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

bool bitan_poredak[105][105];

int R, S;

char grid[105][105];

inline bool check(int s) {
    for (int i = 0; i < R; ++i) {
        for (int j = i + 1; j < R; ++j) {
            if (bitan_poredak[i][j] && grid[i][s] > grid[j][s]) return false;
        }
    }
    return true;
}

int main(void) {
    
    scanf("%d%d", &R, &S);
    for (int i = 0; i < R; ++i) scanf("%s", grid[i]);

    for (int i = 0; i < R; ++i) {
        for (int j = i + 1; j < R; ++j) bitan_poredak[i][j] = true;
    }

    int sol = 0;
    for (int i = 0; i < S; ++i) {
        if (check(i)) {
            for (int r1 = 0; r1 < R; ++r1)
                for (int r2 = r1 + 1; r2 < R; ++r2) 
                    if (bitan_poredak[r1][r2] && grid[r1][i] < grid[r2][i]) bitan_poredak[r1][r2] = false;
        } else {
            ++sol;
        }
    }
    
    printf("%d\n", sol);

    return 0;

}
