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

#define MAXN 100005

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

bool bio[MAXN];

char s1[MAXN], s2[MAXN], s3[MAXN];

int n, t;

char _not(char a, char b) {
    for (char i = 'a'; i <= 'z'; ++i) {
        if (i != a && i != b) return i;
    }
    assert(0);
}

int main(void) {

    scanf("%d%d", &n, &t);

    scanf("%s", s1);
    scanf("%s", s2);

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            if (a == b) {
                ++a; 
                s3[i] = s2[i];
            } else {
                ++b;
                s3[i] = s1[i];
            }
            bio[i] = true;
        }
    }
   
    assert(a >= b);

    if (a > t) {
        printf("-1\n");
        return 0;
    }

    if (a > b) {
        for (int i = 0; i < n; ++i) {
            if (bio[i]) {
                s3[i] = _not(s1[i], s2[i]);
                break;
            }
        }
    }

    b = a;

    for (int i = 0; i < n; ++i) {
        
        if (bio[i]) continue;
        assert(s1[i] == s2[i]);

        if (a < t) {
            ++a; ++b;
            s3[i] = _not(s1[i], s2[i]);
        } else {
            s3[i] = s1[i];
        }

    }

    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            if (a != t && s3[i] == s1[i]) {
                ++a;
                s3[i] = _not(s1[i], s2[i]);
            }
            if (b != t && s3[i] == s2[i]) {
                ++b;
                s3[i] = _not(s1[i], s2[i]);
            }
        }
    }

    if (a != t || b != t)
        printf("-1\n");
    else
        printf("%s\n", s3);

    return 0;

}

