#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 500001

using namespace std;

struct node {

    int l, r;
    int pref_sum[26];

    node () {
        l = r = -1;
        memset(pref_sum, 0, sizeof pref_sum);
    }

    node (int _l, int _r) {
        l = _l;
        r = _r;
        memset(pref_sum, 0, sizeof pref_sum);
    }

    node (int _l, int _r, int a) {
        l = _l;
        r = _r;
        memset(pref_sum, 0, sizeof pref_sum);
        pref_sum[a] = 1;
    }

    friend bool operator < (const node &A, const node &B) {
        return A.l < B.l;
    }

};

char s[MAXN];

int n, m, t, max_lvl;
int dub[MAXN], in[MAXN], out[MAXN];

vector <int> v[MAXN];
vector <node> lvl[MAXN];

void dfs(int curr, int depth) {

    max_lvl = max(max_lvl, depth);
    
    dub[curr] = depth;
    in[curr] = ++t;

    for (int i = 0; i < (int) v[curr].size(); ++i) 
        dfs(v[curr][i], depth + 1);
    
    out[curr] = ++t;
//    lvl[depth].push_back(node(in[curr], out[curr], s[curr] - 'a'));
    
}

inline void calc_pref() {

    for (int i = 0; i < n; ++i) {
        if (lvl[dub[i]].empty()) lvl[dub[i]].push_back(node(-1, -1));
        lvl[dub[i]].push_back(node(in[i], out[i], s[i] - 'a'));
    }

    for (int i = 0; i <= max_lvl; ++i) { 
//        lvl[i].push_back(node(2 * n + 5, -1));
        sort(lvl[i].begin(), lvl[i].end());
        for (int j = 1; j < (int) lvl[i].size(); ++j)
            for (int k = 0; k < 26; ++k)
                lvl[i][j].pref_sum[k] += lvl[i][j - 1].pref_sum[k];
    }
}

inline bool check(const node &A, const node &B) {
    int cnt = 0;
    for (int i = 0; i < 26; ++i)
        cnt += (B.pref_sum[i] - A.pref_sum[i]) % 2;
    return cnt < 2;
}

int main(void) {

    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n - 1; ++i) {
        int x; scanf("%d", &x); --x;
        v[x].push_back(i + 1);
    }

    scanf("%s", s);

    dfs(0, 0); 
    calc_pref();

//    for (int i = 0; i < n; ++i) printf("%d %d\n", tree[i].l, tree[i].r);
//
//    for (int i = 0; i <= max_lvl; ++i) {
//        printf("Level #%d:\n", i);
//        for (int j = 0; j < (int) lvl[i].size(); ++j) 
//            printf("%d %d\n", lvl[i][j].l, lvl[i][j].r);
//    }

    for (int i = 0; i < m; ++i) {
        
        int vi, hi; scanf("%d%d", &vi, &hi); --vi; --hi;
    
        if (hi <= dub[vi] || hi > max_lvl) {
            printf("Yes\n");
            continue;
        }

        int l = (int) (lower_bound(lvl[hi].begin(), lvl[hi].end(), node(in[vi], -1)) - lvl[hi].begin()) - 1;
        int r = (int) (upper_bound(lvl[hi].begin(), lvl[hi].end(), node(out[vi], -1)) - lvl[hi].begin()) - 1;
       
//        printf("%d %d\n", l, r);
//        fflush(stdout);

        if (check(lvl[hi][l], lvl[hi][r])) 
            printf("Yes\n"); 
        else 
            printf("No\n");
    
    }

    return 0;

}
