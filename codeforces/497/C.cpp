#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

#define MAXN 100005

using namespace std;

struct event {
    
    bool is_actor;
    int lo, hi, ind;

    event() {}

    event(bool _is_actor, int _lo, int _hi, int _ind) {
        is_actor = _is_actor;
        lo = _lo;
        hi = _hi;
        ind = _ind;
    }

    friend bool operator < (const event &A, const event &B) {
        if (A.lo == B.lo && A.is_actor == B.is_actor) return A.ind < B.ind;
        if (A.lo == B.lo) return A.is_actor;
        return A.lo < B.lo;
    }

};

struct set_element {
    
    int ind, hi;

    set_element() {}
    
    set_element(int _ind, int _hi) {
        ind = _ind;
        hi = _hi;
    }

    friend bool operator < (const set_element &A, const set_element &B) {
        if (A.hi == B.hi) return A.ind < B.ind;
        return A.hi < B.hi;
    }

};

int N, M;
int k[MAXN], assign[MAXN];

set <set_element> S;
vector <event> E;

int main(void) {

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        E.push_back(event(false, l, r, i));
    }

    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int l, r; scanf("%d%d%d", &l, &r, &k[i]);
        E.push_back(event(true, l, r, i));
    }

    sort(E.begin(), E.end());

    bool success = true;
    for (int i = 0; i < (int) E.size(); ++i) {
       
        if (E[i].is_actor) {
            S.insert(set_element(E[i].ind, E[i].hi));
        } else {
            if (S.empty()) {success = false; break;}
            set <set_element> :: iterator it = S.lower_bound(set_element(-1, E[i].hi));
            if (it == S.end()) {success = false; break; }
            assign[E[i].ind] = it->ind + 1;
            --k[it->ind];
            if (k[it->ind] == 0) S.erase(it);
        }

    }

    if (!success) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < N; ++i) printf("%d ", assign[i]);
        printf("\n");
    }

    return 0;

}
