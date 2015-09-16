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

int len;

char s[15];

inline bool cmp(const char &a, const char &b) {
    return a > b;
}

int main(void) {

    scanf("%d%s", &len, s); 

    string sol = "";
    for (int i = 0; i < len; i++) {
        if (s[i] == '0' || s[i] == '1') continue;
        if (s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7') sol += s[i];
        if (s[i] == '4') sol += "322";
        if (s[i] == '6') sol += "53";
        if (s[i] == '8') sol += "7222";
        if (s[i] == '9') sol += "7332";
    }

    sort(sol.begin(), sol.end(), cmp);
    cout << sol << endl;

    return 0;

}

