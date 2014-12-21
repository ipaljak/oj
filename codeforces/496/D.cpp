#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 100005

using namespace std;

struct out {

    int s, t;

    out () {}
    out (int _s, int _t) {
        s = _s; t = _t;
    }

    friend bool operator < (const out &A, const out &B) {
        if (A.s == B.s) return A.t < B.t;
        return A.s < B.s;
    }

};

int N;
int score_a[MAXN], score_b[MAXN];

vector <out> sol;

int binary_search(int lo, int hi, int t) { // [lo, hi]
    
    int last = lo - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (score_a[mid] - score_a[last] < t && score_b[mid] - score_b[last] < t) lo = mid + 1; else hi = mid;
    }

    return lo;
}

int main(void) {

    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        int x; scanf("%d", &x);
        score_a[i] = score_a[i - 1] + (x == 1);
        score_b[i] = score_b[i - 1] + (x == 2);
    }
    
    for (int t = 1; t <= N; ++t) { // t je broj poena u setu 
        int last = 0, a = 0, b = 0, s;
        bool ok = true;
        while (last != N) {
            int next = binary_search(last + 1, N, t);
            int ascore = score_a[next] - score_a[last], bscore = score_b[next] - score_b[last];
            if (ascore == t || bscore == t) {
                if (ascore > bscore) ++a; else ++b;
                last = next;
            } else {
                ok = false;
                if (next != N) printf("Error that shouldn't happen");
                last = next;
            }
        }
        ok &= a != b;
        if (a > b) ok &= score_a[N] > score_a[N - 1]; else ok &= score_b[N] > score_b[N - 1];
        s = max(a, b);
        if (ok) sol.push_back(out(s, t));
    }

    sort(sol.begin(), sol.end());

    printf("%d\n", (int) sol.size());
    for (int i = 0; i < (int) sol.size(); ++i) 
        printf("%d %d\n", sol[i].s, sol[i].t); 

    return 0;

}
