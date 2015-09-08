#include <algorithm>
#include <cstdio>

#define MAXN 4000

using namespace std;

typedef pair<int, int> pii;

bool know[MAXN][MAXN];

int n, m;
int rec[MAXN];

pii e[MAXN];

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        
        int x, y; scanf("%d%d", &x, &y); --x; --y;
        if (x > y) swap(x, y);
        
        e[i] = make_pair(x, y);
        know[x][y] = know[y][x] = true;
        ++rec[x]; ++rec[y];
    
    }

    sort(e, e + m);

    int sol = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (e[i].second != e[j].first || !know[e[i].first][e[j].second]) continue;
            if (sol == -1 || sol > rec[e[i].first] + rec[e[i].second] + rec[e[j].second])
                sol = rec[e[i].first] + rec[e[i].second] + rec[e[j].second];
        }
    }

    if (sol > 0) printf("%d\n", sol - 6); else printf("-1\n");

    return 0;

}
