#include <cstdio>

using namespace std;

int N;
int contains[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main(void) {
    
    scanf("%d", &N);
    printf("%d\n", contains[N / 10] * contains[N % 10]);
    
    return 0;

}
