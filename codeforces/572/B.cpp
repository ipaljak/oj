#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct order {

    bool buy;
    int price, volume;

    order () {}
    order (bool _buy, int _price, int _volume) {
        buy = _buy;
        price = _price;
        volume = _volume;
    }

    void print() {
        if (buy) printf("B "); else printf("S ");
        printf("%d %d\n", price, volume);
    }

    friend bool operator < (const order &A, const order &B) {
        if (A.buy) 
            return A.price > B.price;
        else
            return A.price < B.price;
    }

};

int n, s;

vector <order> buy, sell;

void update(vector <order> &v, order o) {
    for (int i = 0; i < (int) v.size(); ++i) { 
        if (v[i].price == o.price) {
            v[i].volume += o.volume;
            return;
         }
    }
    v.push_back(o);
}

int main(void) {

    scanf("%d%d", &n, &s);
    
    for (int i = 0; i < n; ++i) {
        
        char s[2]; int p, v;
        scanf("%s%d%d", s, &p, &v);

        if (s[0] == 'B') 
            update(buy, order(true, p, v));
        else 
            update(sell, order(false, p, v));

    }

    sort(buy.begin(), buy.end());
    sort(sell.begin(), sell.end());

    for (int i = min(s, (int) sell.size()) - 1; i >= 0; --i)
        sell[i].print();
    
    for (int i = 0; i < min(s, (int) buy.size()); ++i)
        buy[i].print();

    return 0;

}
