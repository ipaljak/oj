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

char c[] = {'A', 'B', 'C'};

int n, area;
int r[4], s[4];

void sort() {
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 3; ++j) 
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                swap(r[i], r[j]);
                swap(c[i], c[j]);
            }
}

void case1() {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < r[0]) 
                printf("%c", c[0]);
            else if (i < r[0] + r[1])
                printf("%c", c[1]);
            else
                printf("%c", c[2]);
        }
        printf("\n");
    }
}

void case2() {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < r[0]) 
                printf("%c", c[0]);
            else if (i < r[0] + r[1] && j < s[1])
                printf("%c", c[1]);
            else
                printf("%c", c[2]);
        }
        printf("\n");
    }
}

int main(void) {
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d", &r[i], &s[i]);    
        if (r[i] > s[i]) swap(r[i], s[i]);
        area += r[i] * s[i];
    }

    for (; n * n < area; ++n);
    if (n * n != area || max(max(s[0], s[1]), s[2]) > n) {
        printf("-1\n");
        return 0;
    }

    sort();

    if (s[0] == n && s[1] == n && s[2] == n && r[0] + r[1] + r[2] == n) {
        case1();
        return 0;
    }

    for (int i = 0; i < 1 << 2; ++i) {
        for (int j = 0; j < 2; ++j) 
            if ((i & (1 << j))) 
                swap(r[j + 1], s[j + 1]);

        if (s[0] == n && r[1] == r[2] && r[0] + r[1] == n && s[1] + s[2] == n) {
            case2();
            return 0;
        }

        for (int j = 0; j < 2; ++j) 
            if ((i & (1 << j))) 
                swap(r[j + 1], s[j + 1]);
    }

    printf("-1\n");

    return 0;

}

