#include <cstdio>

using namespace std;

int n;

int main(void) {

    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("white\n1 2\n");
    } else {
        printf("black\n");
    }
    
    return 0;

}
