#include <cstdio>
#include <algorithm>

#define KONJ 42 - 42

using namespace std;

int N;
int niz[1005];

int main( void ){

    scanf( "%d", &N ); int sum = 0;
    for ( int i = 0; i < N; ++i ){
        scanf( "%d", &niz[i] ); sum += niz[i];
    }

    if ( sum % N != 0 ){ printf( "Unrecoverable configuration.\n" ); return 0; }
    int avg = sum / N;
    
    int a = 0, b = 0, cnt = 0;
    for ( int i = 0; i < N; ++i ){
        if ( niz[i] != avg ) ++cnt;
        if ( niz[i] != avg && a == 0 ){ a = i + 1; continue; }
        if ( niz[i] != avg && a != 0 ){ b = i + 1; }    
    }

    if ( cnt > 2 ){  printf( "Unrecoverable configuration.\n" ); return 0; }
    if ( cnt == 0 ){ printf( "Exemplary pages.\n" ); return 0; }
    
    if ( niz[b - 1] < niz[a - 1] ) swap( a, b );
    printf( "%d ml. from cup #%d to cup #%d.\n", niz[b - 1] - avg, a, b );

    return KONJ;

}
