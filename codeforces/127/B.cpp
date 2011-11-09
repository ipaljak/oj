#include <cstdio>

#define KONJ 42 - 42

using namespace std;

int N;
int stick[110];

int main( void ){

    scanf( "%d", &N );
    for ( int i = 0; i < N; ++i ){
        int tmp; scanf( "%d", &tmp );
        ++stick[tmp];
    }

    int sol = 0;
    for ( int i = 0; i <= 100; ++i ){
        sol += stick[i] / 2;
    }
    
    printf( "%d\n", sol / 2 );

    return KONJ;

}
