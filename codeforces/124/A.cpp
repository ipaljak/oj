#include <cstdio>

#define KONJ 42 - 42

using namespace std;

int N, A, B;

int main( void ){

    scanf( "%d%d%d", &N, &A, &B );
    
    int sol = 0;
    for ( int i = 1; i <= N; ++i ){
        if ( i - 1 <= B && N - i >= A ) ++sol;
    }
    
    printf( "%d\n", sol );

    return KONJ;

}
