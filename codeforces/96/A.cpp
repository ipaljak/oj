#include <cstdio>
#include <cstring>

#define KONJ 42 - 42

using namespace std;

char s[110];

int main( void ){

    scanf( "%s", s ); int len = strlen( s );
    
    int tmp = 1; bool dang = false;
    for ( int i = 1; i < len; ++i ){
        if ( s[i] == s[i - 1] ){ ++tmp; } else { tmp = 1; }
        if ( tmp >= 7 ) dang = true; 
    }

    if ( dang ){ printf( "YES\n" ); } else { printf( "NO\n" ); }

    return KONJ;
    
}
