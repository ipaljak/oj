#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int n;
int a[510];

multiset <int> s;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; scanf("%d", &x);
            s.insert(x);
        }
    } 

    multiset <int> :: reverse_iterator rit;

    for (int i = n - 1; i >= 0; --i) {
        rit = s.rbegin();
        a[i] = *rit;
        for (int j = i; j < n; ++j) { 
            s.erase(s.find(gcd(a[i], a[j])));
            if (i != j) s.erase(s.find(gcd(a[i], a[j])));
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);

    printf("\n");

    return 0;

}

