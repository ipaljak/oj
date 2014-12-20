#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int prev, curr;

int main(void) {

    scanf("%d%d%d", &N, &prev, &curr);
    
    int A = 5000, B = curr - prev;
    for (int i = 0; i < N - 2; ++i) {
        int x; scanf("%d", &x);
        A = min(A, x - prev);
        B = max(B, x - curr);
        prev = curr; curr = x;
    }
   
    printf("%d\n", max(A, B));

    return 0;

}
