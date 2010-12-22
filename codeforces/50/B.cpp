#include <cstdio>
#include <cstring>

#define KONJ 42 - 42

using namespace std;

int len;
char s[100010];
long long niz[50]; // 0 = 1.. a = 10 

int main( void ){

    scanf( "%s", s ); len = strlen( s );
    for ( int i = 0; i < len; ++i ){
        if ( s[i] >= '0' && s[i] <= '9' ){ ++niz[ s[i] - '0' ]; } else { ++niz[ s[i] - 'a' + 10 ]; }
    }
    
    long long sol = 0;
    for ( int i = 0; i < 50; ++i ){
        sol += niz[i] * niz[i];
    }
    
    printf( "%lld\n", sol );
    
    return KONJ;

}
