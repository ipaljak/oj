#include <cstdio>

using namespace std;

char feature[101][101];

int r, s;
int value[101][101];

void increase(int _r, int _s, int val) {
    for (int i = 0; i <= _r; ++i)
        for (int j = 0; j <= _s; ++j)
            value[i][j] += val;
}

int main(void) {

    scanf("%d%d", &r, &s);
    for (int i = 0; i < r; ++i)
        scanf("%s", feature[i]);

    int sol = 0;
    for (int i = r - 1; i >= 0; --i) {
        for (int j = s - 1; j >= 0; --j) {
            
            if (value[i][j] == 1 && feature[i][j] == 'W') continue;
            if (value[i][j] == -1 && feature[i][j] == 'B') continue;
            
            int add = 1 - value[i][j];
            if (feature[i][j] == 'B') add = -1 - value[i][j];

            increase(i, j, add); ++sol;

        }
    }

    printf("%d\n", sol);

    return 0;

}
