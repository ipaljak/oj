#include <algorithm>
#include <cstdio>

using namespace std;

struct frajer {
    
    int ind, val; 
    
    frajer () {}
    friend bool operator < (const frajer &A, const frajer &B) {
        return A.val - A.ind > B.val - B.ind;
    }

};

int N;

frajer F[200010];

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &F[i].val);
        F[i].ind = N - i - 1;
    }

    sort(F, F + N);

    F[0].val -= F[0].ind;
    for (int i = 1; i < N; ++i) {
        F[i].val += i - F[i].ind; 
        if (F[i].val > F[i - 1].val) {
            printf(":(\n");
            return 0;
        }
    }

    for (int i = N - 1; i >= 0; --i) printf("%d ", F[i].val);
    printf("\n");

    return 0;

}
