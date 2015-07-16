#include <algorithm>
#include <cstdio>

using namespace std;

struct element {
    
    int cnt, l, r;
    
    element () { 
        cnt = 0; 
        l = 1000000;
        r = 0;
    }

    void update(int i) {
        ++cnt; 
        l = min(l, i);
        r = max(r, i);
    }

};

int n;

element val[1000001];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x); --x;
        val[x].update(i);
    }

    int pivot = 0;
    for (int i = 1; i < 1000000; ++i) {
        if (val[i].cnt > val[pivot].cnt) {
            pivot = i;
        }
        if (val[i].cnt == val[pivot].cnt && val[i].r - val[i].l < val[pivot].r - val[pivot].l) {
            pivot = i;
        }
    }
    
    printf("%d %d\n", val[pivot].l + 1, val[pivot].r + 1);

    return 0;

}
