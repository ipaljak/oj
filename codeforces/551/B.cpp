#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXLEN 100001

using namespace std;

char s[MAXLEN], a[MAXLEN], b[MAXLEN];

int len_s, len_a, len_b;
int cnt_s[27], cnt_a[27], cnt_b[27];

void count_letters(int len, char *str, int *ret) {
    for (int i = 0; i < len; ++i) 
        ++ret[str[i] - 'a'];
}

inline bool check(int x) {
    for (int i = 0; i < 26; ++i) {
        if (cnt_s[i] - x * cnt_a[i] < 0) return false;
    }
    return true;
}

inline int b_num(int x) {
    int ret = 100000000;
    for (int i = 0; i < 26; ++i) {
        if (cnt_b[i] == 0) continue;
        ret = min(ret, (cnt_s[i] - cnt_a[i] * x) / cnt_b[i]);
    }
    return ret;
}

int main(void) {

    scanf("%s%s%s", s, a, b);
    
    len_s = strlen(s);
    len_a = strlen(a);
    len_b = strlen(b);

    count_letters(len_s, s, cnt_s);
    count_letters(len_a, a, cnt_a);
    count_letters(len_b, b, cnt_b);

    int a_num = 0, ret = 0, pivot = 0;
    while (check(a_num)) {
        if (a_num + b_num(a_num) > ret) pivot = a_num;
        ret = max(ret, a_num + b_num(a_num));
        ++a_num;
    }

    for (int i = 0; i < pivot; ++i) printf("%s", a);
    for (int i = 0; i < ret - pivot; ++i) printf("%s", b);

    for (int i = 0; i < 26; ++i) {
        cnt_s[i] -= pivot * cnt_a[i] + (ret - pivot) * cnt_b[i];
        for (int j = 0; j < cnt_s[i]; ++j) printf("%c", 'a' + i);
    }

    printf("\n");

    return 0;

}
