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

#define MAXLEN 100010

using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

int len;
char s[MAXLEN];

string word;

vector <string> numbers;
vector <string> words;

inline bool is_number(string &w) {
    if (w.size() == 0 || (w[0] == '0' && w.size() != 1)) return false;
    for (int i = 0; i < (int) w.size(); ++i) 
        if (w[i] < '0' || w[i] > '9') 
            return false;
    return true;
}

inline void print_vec(vector <string> &v) {
    if (v.size() == 0) {
        printf("-\n");
        return;
    }
    printf("\"");
    for (int i = 0; i < (int) v.size(); ++i) {
        for (int j = 0; j < (int) v[i].size(); ++j)
            printf("%c", v[i][j]);
        if (i != (int) v.size() - 1) 
            printf(",");
    }
    printf("\"\n");
}

int main(void) {

    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len; ++i) {
        if (s[i] == ';' || s[i] == ',') {
            if (is_number(word))
                numbers.push_back(word);
            else
                words.push_back(word);
            word.clear();
            continue;
        }
        word.push_back(s[i]);
    } 

    if (is_number(word))
        numbers.push_back(word);
    else
        words.push_back(word);
    
    print_vec(numbers);
    print_vec(words);

    return 0;

}

