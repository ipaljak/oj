#include <algorithm>
#include <cstdio>

using namespace std;

struct kos {
    
    int team, pos;
    
    kos () {}
    kos (int _team, int _pos) {
        team = _team; pos = _pos;
    }

    friend bool operator < (const kos &A, const kos &B) {
        return A.pos < B.pos;
    }

};

int n, m;

kos K[4 * 100001];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        K[i] = kos(1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x; scanf("%d", &x);
        K[i + n] = kos(2, x);
    }

    sort(K, K + n + m);
    
    int scored_a = 0, scored_b = 0;
    int sol_a = 3 * n, sol_b = 3 * m;

    for (int i = 0; i < n + m; ++i) {
        
        int _pos = K[i].pos;
        int ind = i;
        
        while (ind < n + m && K[ind].pos == _pos) {
            if (K[ind].team == 1) ++scored_a; else ++scored_b;
            ++ind;
        }

        if (2 * scored_a + 3 * (n - scored_a) - 2 * scored_b - 3 * (m - scored_b) > sol_a - sol_b) {
            sol_a = 2 * scored_a + 3 * (n - scored_a);
            sol_b = 2 * scored_b + 3 * (m - scored_b);
        }

        i = ind - 1;

    }   

    printf("%d:%d\n", sol_a, sol_b);

    return 0;

}
