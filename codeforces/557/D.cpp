#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#define RED 1
#define BLACK 2

typedef long long llint;

using namespace std;

bool bicolorable = true; 

int n, m, red, black;
int color[100010];

vector <int> v[100010];

void dfs(int node) {
    
    for (int i = 0; i < (int) v[node].size(); ++i) {
        int next = v[node][i];
        if (!color[next]) {
            if (color[node] == RED) {
                color[next] = BLACK; 
                ++black;
            } else {
                color[next] = RED;
                ++red;
            }
            dfs(next);
            continue;
        }
        if (color[next] == color[node]) bicolorable = false;
    }

}

int main(void) {

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b); --a; --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    llint sol = 0;
    for (int i = 0; i < n; ++i){ 
        red = 0; black = 1;
        if (!color[i]) {
            color[i] = BLACK;
            dfs(i);
            if (red + black >= 3) {
                sol += (llint) red * (red - 1) / 2;
                sol += (llint) black * (black - 1) / 2;
            }
        }
    }
   
    if (!bicolorable) {
        printf("0 1\n");
        return 0;
    }

    if (sol != 0LL) {
        printf("1 %I64d\n", sol);
        return 0;
    }
    
    for (int i = 0; i < n; ++i) {
        if (v[i].size() == 1) sol += (llint) n - 2;
    }

    if (sol != 0LL) {
        printf("2 %I64d\n", sol / 2);
    } else {
        printf("3 %I64d\n", (llint) n * (n - 1) * (n - 2) / 6LL);
    }

    return 0;

}
