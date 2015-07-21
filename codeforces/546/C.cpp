#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXMOVES 37000000

using namespace std;

int n, k1, k2;
int a[11], b[11];

deque <int> s1, s2;

int main(void) {

    scanf("%d", &n);

    scanf("%d", &k1);
    for (int i = 0; i < k1; ++i) scanf("%d", &a[i]);
    for (int i = k1 - 1; i >= 0; --i) s1.push_front(a[i]);

    scanf("%d", &k2);
    for (int i = 0; i < k2; ++i) scanf("%d", &b[i]);
    for (int i = k2 - 1; i >= 0; --i) s2.push_front(b[i]);

    for (int i = 0; i < MAXMOVES; ++i) {
        
        if (s1.empty()) {
            printf("%d 2\n", i);
            return 0;
        }

        if (s2.empty()) {
            printf("%d 1\n", i);
            return 0;
        }
    
        int _a = s1.front(); s1.pop_front();
        int _b = s2.front(); s2.pop_front();

        if (_a > _b) {
            s1.push_back(_b);
            s1.push_back(_a);
        } else {
            s2.push_back(_a);
            s2.push_back(_b);
        }

    }

    printf("-1\n");

    return 0;

}
