#include <cstdio>
#include <cstring>

using namespace std;

int sum, n, last, last_sum;
char s[100005];

int main(void) {

    scanf("%s", s); int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '('){ ++sum; continue; }
        if (s[i] == '#'){ last = i; last_sum = sum - 1; ++n; }
        --sum; if (sum < 0) {printf("-1\n"); return 0;}
    } 

    last_sum -= sum;
    if (last_sum < 0){ printf("-1\n"); return 0;}

    for (int i = last + 1; i < len; ++i) {
        if (s[i] == '(') ++last_sum; else --last_sum;
        if (last_sum < 0) {printf("-1\n"); return 0;}
    }

    for (int i = 0; i < n - 1; ++i) printf("1\n");
    printf("%d\n", sum + 1);

    return 0;

}
