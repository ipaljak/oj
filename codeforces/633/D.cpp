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
#include <unordered_map>

#define MAXN 1010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;
int a[MAXN];

unordered_map<int, int> m;

int main(void) {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        m[a[i]]++;
    }

//    if (all_zeros) {
//        printf("%d\n", n);
//        return 0;
//    }

    int sol = 0, tmp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            
            if (i == j || (a[i] == 0 && a[j] == 0)) continue;

            int A = a[i], B = a[j];
            
            m[a[i]]--;
            m[a[j]]--;
            
            tmp = 2; 
            while (m.find(A + B) != m.end() && m[A + B] > 0) {
                m[A+B]--;
                int _B = A + B; 
                A = B;
                B = _B;
                ++tmp;
            }

            sol = max(sol, tmp); 
            m[a[i]]++;
            m[a[j]]++;
            A = a[i], B = a[j];

            tmp -= 2;
            while (tmp > 0) {
                --tmp; 
                m[A+B]++;
                int _B = A + B; 
                A = B;
                B = _B;
            }

        }
    }

    printf("%d\n", max(m[0], sol));

    return 0;

}

