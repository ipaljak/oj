#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;

int m, h1, a1, x1, y1, h2, a2, x2, y2, h;
int bio[1000001];

pair <int, int> find(int h, int a, int x, int y) {
    
    memset(bio, 0, sizeof bio);

    int _t = 2000000, _c = 0;
    int curr = h, t = 0; 
    while (true) {
        bio[curr] = t;
        if (curr == a) _t = t;
        curr = ((long long) x * curr + y) % m;
        if (bio[curr] != 0) {
            if (bio[curr] <= _t) {
                _c = t + 1 - bio[curr];
            } else {
                _c = 0;
            }
            break;
        }
        ++t;
    }

    if (bio[a] == 0) return make_pair(-1, -1);
    return make_pair(_t, _c);

}

void brute() {

    printf("Brute: ");

    for (int t = 1; t < 1000000; ++t) {
        h1 = (h1 * x1 + y1) % m;
        h2 = (h2 * x2 + y2) % m;
        if (h1 == a1 && h2 == a2) {
            printf("%d\n", t);
            return;
        }
    }
    
    printf("-1\n");


}

int main(void) {

    scanf("%d", &m);
    scanf("%d%d%d%d", &h1, &a1, &x1, &y1);
    scanf("%d%d%d%d", &h2, &a2, &x2, &y2);

    pair<int, int> p1 = find(h1, a1, x1, y1); int _h = h;
    pair<int, int> p2 = find(h2, a2, x2, y2);
    
    if (p1.first == -1 || p2.first == -1) {
        printf("-1\n");
        return 0;
    }

    memset(bio, 0, sizeof bio);
     //printf("%d %d\n%d %d\n", p1.first, p1.second, p2.first, p2.second);

    if (p2.second == 0) {
        if (p1.second == 0) {
            if (p1.first == p2.first) printf("%d\n", p1.first); else printf("-1\n");
            return 0;
        } 
        if (p2.first >= p1.first && (p2.first - p1.first) % p1.second == 0) printf("%d\n", p2.first); else printf("-1\n");
        return 0;
    }
    for (int k = 0; k < 1000000; ++k) {
        long long val = p1.first + (long long) k * p1.second;
        if (val >= p2.first && (val - p2.first) % p2.second == 0) {
            printf("%I64d\n", val);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
    
}
