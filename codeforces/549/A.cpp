#include <cstdio>

using namespace std;

int r, s;

char grid[51][51];

inline bool check(int i, int j, char c) {
    return grid[i][j] == c || grid[i + 1][j] == c || grid[i][j + 1] == c || grid[i + 1][j + 1] == c;
}

int main(void) {

    scanf("%d%d", &r, &s);
    for (int i = 0; i < r; ++i) 
        scanf("%s", grid[i]);

    int ret = 0;
    for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < s - 1; ++j) {
            if (check(i, j, 'f') && check(i, j, 'a') && check(i, j, 'c') && check(i, j, 'e')) ++ret; 
        }
    }

    printf("%d\n", ret);

    return 0;

}
