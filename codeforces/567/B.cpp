#include <algorithm>
#include <cstdio>

#define MAXN 101
#define MAXID 1000010

using namespace std;

bool sign[MAXN], seen[MAXID];

int n, start;
int id[MAXN];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char s[2]; scanf("%s%d", s, &id[i]);
        sign[i] = s[0] == '+';
        if (!seen[id[i]]) start += !sign[i];
        seen[id[i]] = true;
    }

    int sol = start;
    for (int i = 0; i < n; ++i) {
        if (sign[i]) ++start; else --start;
        sol = max(sol, start);
    }

    printf("%d\n", sol);
    
    return 0;

}
