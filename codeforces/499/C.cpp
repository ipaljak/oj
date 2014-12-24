#include <cstdio>

typedef long long llint;

using namespace std;

int N;
llint x1, x2, y1, y2;

int main(void) {

    scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
    scanf("%d", &N);

    int sol = 0;
    for (int i = 0; i < N; ++i) {
        llint a, b, c; scanf("%I64d%I64d%I64d", &a, &b, &c);
        sol += x1 * a + y1 * b + c < 0LL && x2 * a + y2 * b + c > 0LL;
        sol += x1 * a + y1 * b + c > 0LL && x2 * a + y2 * b + c < 0LL;
    }

    printf("%d\n", sol);

    return 0;

}
