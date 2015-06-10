#include <cstdio>

using namespace std;

bool bio[101];

char adj[101][101];

int n;
int q[101];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", adj[i]);
    
    for (int i = 0; i < n; ++i) 
        scanf("%d", &q[i]);

    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < n; ++i) {
            if (q[i] != 0 || bio[i]) continue;
            bio[i] = true;
            for (int j = 0; j < n; ++j) {
                if (adj[i][j] == '1') --q[j];
            }
            break;
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += bio[i];
        if (q[i] == 0){
            ret = -1;
            break;
        }
    }

    printf("%d\n", ret);
    for (int i = 0; i < n; ++i) {
        if (bio[i]) printf("%d ", i + 1);
    }

    if (ret > 0) printf("\n");
    
    return 0;

}
