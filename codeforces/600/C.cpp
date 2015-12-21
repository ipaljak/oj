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

#define MAXLEN 200010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int len;
int cnt[27];

char s[MAXLEN];

int main(void) {

    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len; ++i)
        ++cnt[s[i] - 'a'];

    vector <int> odd_indices;
    for (int i = 0; i < 26; ++i) 
        if (cnt[i] & 1) odd_indices.push_back(i);

    for (int i = 0; i < (int) odd_indices.size() / 2; ++i) {
        ++cnt[odd_indices[i]];
        --cnt[odd_indices[(int) odd_indices.size() - 1 - i]];
    }

    int middle = -1;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] & 1) middle = i;
        for (int j = 0; j < cnt[i] / 2; ++j)
            printf("%c", 'a' + i);
    }
    
    if (middle != -1) 
        printf("%c", 'a' + middle);

    for (int i = 25; i >= 0; --i)
        for (int j = 0; j < cnt[i] / 2; ++j)
            printf("%c", 'a' + i);

    printf("\n");

    return 0;

}

