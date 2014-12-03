#include <algorithm>
#include <cstdio>

typedef long long llint;

using namespace std;

bool last;

int n, fst_cnt, snd_cnt;
int fst_pts[200002], snd_pts[200002];

llint sum_a, sum_b;

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        if (x > 0) {
            last = false;
            fst_pts[fst_cnt++] = x;
            sum_a += (llint) x;
        } else {
            x *= -1;
            last = true;
            snd_pts[snd_cnt++] = x;
            sum_b += (llint) x;
        }
    }
   
    if (sum_a > sum_b) printf("first\n");
    if (sum_a < sum_b) printf("second\n");

    if (sum_a == sum_b) {
        
        int cmp = 0;
        for (int i = 0; i < min(fst_cnt, snd_cnt); ++i) {
            if (fst_pts[i] > snd_pts[i]) {cmp = -1; break;}
            if (fst_pts[i] < snd_pts[i]) {cmp = 1; break;}
        }
       
        if (cmp == 0 && fst_cnt > snd_cnt) cmp = -1;
        if (cmp == 0 && fst_cnt < snd_cnt) cmp = 1;

        if (cmp == 0 && last) cmp = 1;
        if (cmp == 0 && !last) cmp = -1;

        if (cmp == 1) printf("second\n"); else printf("first\n");

    }

    return 0;

}
