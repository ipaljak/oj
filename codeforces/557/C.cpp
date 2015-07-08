#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct leg {
    
    int len, energy, ind;
    
    leg() {}
    leg(int _len, int _energy) {
        len = _len;
        energy = _energy;
    }

    friend bool operator < (const leg &A, const leg &B) {
        if (A.len == B.len) return A.energy > B.energy;
        return A.len > B.len;
    }

};

int n, total;
int loga_bit[100010], loga_e[100010];

leg L[100010];

inline bool cmp_energy(const leg &A, const leg &B) {
    return A.energy > B.energy;
}

void add(int i, int val, int *loga){
    for ( ; i <= n; i += i & -i) loga[i] += val; 
}

int sum(int lo, int hi, int *loga) {
    int ret = 0;
    for ( ; hi > 0; hi -= hi & -hi) ret += loga[hi];
    for ( --lo; lo > 0; lo -= lo & -lo) ret -= loga[lo];
    return ret;
}

int main(void) {

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) scanf("%d", &L[i].len);
    for (int i = 0; i < n; ++i) scanf("%d", &L[i].energy);
    
    sort(L, L + n, cmp_energy);

    for (int i = 0; i < n; ++i) {
        L[i].ind = i + 1;
        add(i + 1, 1, loga_bit);
        add(i + 1, L[i].energy, loga_e);
        total += L[i].energy;
    }

    sort(L, L + n);
    
    int left = 0, prev_len = L[0].len, size = 0, sol = total + 1;
    for (int i = 0; i < n; ++i) {
        
        if (L[i].len == prev_len) {
            ++size;
        } else {
            size = 1; left = 0;
            prev_len = L[i].len;
        }

        int target = size - 1;
        int lo = 1, hi = n, mid;
   
        left += L[i].energy;
        add(L[i].ind, -1, loga_bit);
        add(L[i].ind, -L[i].energy, loga_e);

        while (lo != hi) {
            mid = (lo + hi) / 2;
            if (sum(1, mid, loga_bit) < target) lo = mid + 1; else hi = mid;
        }

        if (size == 1) {
            sol = min(sol, total - L[i].energy);
        } else {
//            printf("--> %d %d <-- ", left, sum(1, lo, loga_e));
            sol = min(sol, total - left - sum(1, lo, loga_e));
        }

//        printf("%d %d %d\n", target, lo, sol);
        
    }
    
    printf("%d\n", sol);

    return 0;

}
