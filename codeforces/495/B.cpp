#include <cstdio>

using namespace std;

int a, b;

int main(void) {

    scanf("%d%d", &a, &b); 

    a -= b;
    if (a == 0) {
        printf("infinity\n");
        return 0;
    }

    int sol = 0;
    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            sol += (i > b) + (a / i > b);
        }
        if (i * i == a && i > b) --sol;
    }

    printf("%d\n", sol);

    return 0;

}
