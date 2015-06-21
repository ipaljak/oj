#include <cstdio>

using namespace std;

int N;
int S[2000];

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) 
        scanf("%d", &S[i]);

    for (int i = 0; i < N; ++i) {
        int pos = 0;
        for (int j = 0; j < N; ++j) 
           pos += S[j] > S[i];
        printf("%d ", pos + 1);
    }

    printf("\n");

    return 0;

}
