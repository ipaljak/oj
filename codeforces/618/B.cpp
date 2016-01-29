#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

bool bio[55];

int n; 
int mat[55][55], sol[55];

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (bio[j]) continue;
            int cnt = 0;
            for (int k = 0; k < n; ++k) 
                cnt += mat[j][k] == i;
            if (cnt == n - i) {
                sol[j] = i;
                bio[j] = true;
                break;    
            }
        }
    }   

    for (int i = 0; i < n; ++i)
        printf("%d ", sol[i]);

    printf("\n");

    return 0;

}

