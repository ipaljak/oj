#include <cstdio>

#define KONJ 42 - 42

using namespace std;

long long R, S, A;

int main( void ){

    scanf( "%lld%lld%lld", &R, &S, &A );
    //if ( R == 0 || S == 0 ){ printf( "0\n" ); return KONJ; }
    printf( "%lld\n", ( R / A + !( R % A == 0 ) ) * ( S / A + !( S % A == 0 ) ) );

    return KONJ;

}
