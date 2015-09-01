#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int r, s;
int grid[101][101], city[101];

int main(void) {

    scanf("%d%d", &s, &r);
    for (int i = 0; i < r; ++i) {
        int pivot = 0;
        for (int j = 0; j < s; ++j) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] > grid[i][pivot]) pivot = j;
        }
        ++city[pivot];
    }

    int pivot = 0;
    for (int i = 0; i < s; ++i)
        if (city[i] > city[pivot]) pivot = i;

    printf("%d\n", pivot + 1);

    return 0;

}
