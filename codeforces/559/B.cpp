#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

#define MAXN 200010

using namespace std;

string s1, s2;

string smallest(string s) {
    if (s.length() % 2) return s;
    string left = smallest(s.substr(0, s.length() / 2));
    string right = smallest(s.substr(s.length() / 2, s.length()));
    if (left < right) return left + right; else return right + left;
}

int main(void) {

    cin >> s1;
    cin >> s2;

    if (smallest(s1) == smallest(s2)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;

}
