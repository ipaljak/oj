#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long llint;

using namespace std;

int l;

llint n, m, k;

struct matrix {
    
    long long M[3][3];

    matrix() {
        memset(M, 0, sizeof M);
    }

    void clear() {
        memset(M, 0, sizeof M);
    }

    friend matrix operator * (const matrix &A, const matrix &B) {
        
        matrix ret;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    ret.M[i][j] += A.M[i][k] * B.M[k][j];
                    ret.M[i][j] %= m;
                }
            }
        }

        return ret;

    }

} sol, X, B;

void init() {
    
    sol.clear();
    X.clear();
    B.clear();

    sol.M[0][0] = sol.M[1][1] = 1;
    B.M[0][0] = 1; B.M[0][1] = 1;
    X.M[0][0] = X.M[1][0] = X.M[0][1] = 1;

}

llint nth_fib(llint exp) {
    init();
    while (exp > 0) {
        if (exp & 1) sol = sol * X;
        exp >>= 1; X = X * X;
    }
    sol = B * sol;
    return sol.M[0][0];
}

llint nth_pow(llint b, llint exp) {
    llint ret = 1;
    while (exp > 0) {
        if (exp & 1) { ret *= b; ret %= m; }
        exp >>= 1; b *= b; b %= m;
    }
    return ret;
}

int main(void) {

    scanf("%I64d%I64d%d%I64d", &n, &k, &l, &m);
    if (l < 63 && (1LL << l) <= k) {
        printf("0\n");
        return 0;
    }

    int zero = 0, one = 0;
    for (int i = 0; i < min(62, l); ++i) {
        if (k & (1LL << i)) ++one; else ++zero;
    }

    if (l >= 63) zero += l - 62;

    llint fib = nth_fib(n);
    llint ret = nth_pow(fib, zero);
    ret *=  nth_pow(nth_pow(2LL, n) - fib + 2 * m, one) % m;
    ret %= m;

    printf("%I64d\n", ret);

    return 0;

}
