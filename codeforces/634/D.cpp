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

int d, n, m;

vector <pii> gas;
deque <pii> dq;

int main(void) {

    scanf("%d%d%d", &d, &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        gas.emplace_back(a, b);
    }

    sort(gas.begin(), gas.end()); 
    gas.emplace_back(d, 0);
        
    int prev = 0, tank = n;
    llint money = 0;
   
    dq.push_front({0, n});

    for (auto st : gas) {
       
        int dist = st.first - prev;
        tank -= dist;

        while (dist > 0 && !dq.empty()) {
            if (dist >= dq.front().second) {
                dist -= dq.front().second;
                dq.pop_front(); 
                continue;
            }
            dq.front().second -= dist;
            dist = 0;
        }

        if (dist > 0) {
            assert(tank < 0);
            printf("-1\n");
            return 0;
        }

        while (!dq.empty() && dq.back().first > st.second) {
            money += (llint) dq.back().first * dq.back().second;
            tank -= dq.back().second; 
            dq.pop_back();
        } 

        if (st.first == d) break;

        money -= (llint) (n - tank) * st.second; 
        dq.push_back({st.second, n - tank});
        tank = n;
        prev = st.first; 
    
    }

//    while (!dq.empty()) {
//        money += (llint) dq.front().first * dq.front().second; 
//        dq.pop_front(); 
//    }

    printf("%lld\n", -money);
    
    return 0;

}

