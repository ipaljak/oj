#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N; 

string number;
vector <string> v;

int main(void) {

    scanf("%d", &N);
    cin >> number;
    
    for (int i = 0; i < N; ++i) {

        v.push_back(number);
        for (int dig = 1; dig < 10; ++dig) {
            for (int j = 0; j < N; ++j) {
                number[j] = '0' + ((number[j] - '0' + 1) % 10);
            }
            v.push_back(number);
        }

        number = number[N - 1] + number.substr(0, N - 1);

    }

    string sol = v[0];
    for (int i = 0; i < (int) v.size(); ++i) {
        if (v[i] < sol) sol = v[i];
    }

    cout << sol << endl;

    return 0;

}
