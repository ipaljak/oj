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

int m;

vector<int> sol;

int main(void) {

    scanf("%d", &m);
    
    int n = 1, zeros = 0; 
    while (zeros <= m) {
        
        int _n = n;
        while (_n % 5 == 0) {
            _n /= 5;
            ++zeros; 
        }

        if (zeros == m) 
            sol.push_back(n); 

        ++n; 

    }

    printf("%d\n", (int) sol.size());
    for (int i = 0; i < (int) sol.size(); ++i) {
        printf("%d ", sol[i]);
    }

    printf("\n");

    return 0;

}

