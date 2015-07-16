#include <algorithm>
#include <cstdio>

using namespace std;

struct tree {
    
    int x, a;
    
    tree () {}
    tree (int _x, int _a) {
        x = _x;
        a = _a;
    }

    friend bool operator < (const tree &A, const tree &B) {
        return A.x < B.x;
    }

};

int n, l_cnt, r_cnt;

tree left[101], right[101];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, a; scanf("%d%d", &x, &a);
        if (x < 0) {
            left[l_cnt++] = tree(-x, a);
        } else {
            right[r_cnt++] = tree(x, a);
        }
    }

    sort(left, left + l_cnt);
    sort(right, right + r_cnt);

    int sol = 0;
    for (int i = 0; i < min(l_cnt, r_cnt); ++i) 
        sol += left[i].a + right[i].a;

    if (l_cnt > r_cnt) sol += left[r_cnt].a; else sol += right[l_cnt].a;
    printf("%d\n", sol);

    return 0;

}
