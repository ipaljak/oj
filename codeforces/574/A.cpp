#include <cstdio> 

using namespace std;

int n;
int votes[101];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &votes[i]);
    }

    int pivot = 1, sol = 0;
    while (pivot != 0) {
        for (int i = 0; i < n; ++i) {
            if (votes[i] >= votes[pivot]) pivot = i;
        }
        if (pivot != 0) {
            --votes[pivot];
            ++votes[0];
            ++sol;
        } 
    }

    printf("%d\n", sol);

}
