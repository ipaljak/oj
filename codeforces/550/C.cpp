#include <cstdio>
#include <cstring>

using namespace std;

char s[101];

int len;

int main(void) {

    scanf("%s", s);
    len = strlen(s);

    for (int i = 0; i < len; ++i) {

        if ((s[i] - '0') % 8 == 0) {
            printf("YES\n%c\n", s[i]);
            return 0;
        }
    
        for (int j = i + 1; j < len; ++j) {
            
            if ((10 * (s[i] - '0') + (s[j] - '0')) % 8 == 0) {
                printf("YES\n%c%c\n", s[i], s[j]); 
                return 0;
            }

            for (int k = j + 1; k < len; ++k) {
                if ((100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0')) % 8 == 0) {
                    printf("YES\n%c%c%c\n", s[i], s[j], s[k]);
                    return 0;
                }
            }   

        }
    }

    printf("NO\n");

    return 0;

}
