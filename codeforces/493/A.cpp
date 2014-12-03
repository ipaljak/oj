#include <cstdio>

using namespace std;

bool has_yellow[3][100], has_red[3][100];

char team_name[3][25];

int n;

int main(void) {

    scanf("%s%s", team_name[0], team_name[1]);
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        
        int minute, number; 
        char team, card;
        scanf("%d %c %d %c\n", &minute, &team, &number, &card);
        
        bool t = team == 'a';
        if (has_red[t][number]) continue;
        
        if (has_yellow[t][number] && card == 'y') {
            printf("%s %d %d\n", team_name[t], number, minute);
            has_red[t][number] = true;
            continue;
        }
        
        if (!has_yellow[t][number] && card == 'y') {
            has_yellow[t][number] = true;
            continue;
        }

        if (card == 'r') {
            has_red[t][number] = true;
            printf("%s %d %d\n", team_name[t], number, minute);
        }

    }

    return 0;

}
