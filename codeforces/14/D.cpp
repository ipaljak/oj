#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define MAXN 100010

using namespace std;

typedef long long llint;
typedef pair <int, int> pii;

bool bio[MAXN];

int n;
int down[MAXN], up[MAXN];

vector <int> v[MAXN];
vector <pii> depth[MAXN];

inline bool cmp(const pii &A, const pii &B) {
    if (A.first == B.first) return A.second > B.second;
    return A.first > B.first;
}

int solve_down(int node) {

    int ret = 1;
    bio[node] = true; 

    for (int i = 0; i < (int) v[node].size(); ++i) {
        
        int next = v[node][i];
        if (bio[next]) continue;

        int next_depth = solve_down(next);
        depth[node].push_back(make_pair(next_depth, next));

        ret = max(ret, 1 + next_depth);

    }

    sort(depth[node].begin(), depth[node].end(), cmp);
    
    if (depth[node].size() == 0) down[node] = 1;
    if (depth[node].size() == 1) down[node] = depth[node][0].first + 1;
    if (depth[node].size() > 1)  down[node] = depth[node][0].first + depth[node][1].first + 1;

    return ret;

}

void solve_up(int node, int l) {
    
    bio[node] = true;

    depth[node].push_back(make_pair(l, MAXN));
    sort(depth[node].begin(), depth[node].end(), cmp);

    for (int i = 0; i < (int) v[node].size(); ++i) {
        
        int next = v[node][i];
        if (bio[next]) continue;

        int x = depth[node][0].first + depth[node][1].first, y = depth[node][0].first;

        if (depth[node].size() == 2) 
            x = y = l;
        else if (depth[node][0].second == next)
            x = depth[node][1].first + depth[node][2].first, y = depth[node][1].first;
        else if (depth[node][1].second == next)
            x = depth[node][0].first + depth[node][2].first;
        
        up[next] = max(up[node], x + 1);
        solve_up(next, y + 1);

    }

}

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        v[a].push_back(b); v[b].push_back(a);
    }

    solve_down(0);
    memset(bio, false, sizeof bio);
    solve_up(0, 0);
    
    // for (int i = 0; i < n; ++i) printf("%d %d\n", up[i], down[i]);

    llint sol = 0;
    for (int i = 1; i < n; ++i)
        sol = max(sol, (llint) (up[i] - 1) * (down[i] - 1));
    
    printf("%I64d\n", sol);

    return 0;

}
