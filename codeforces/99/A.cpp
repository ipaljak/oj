#include <cstdio>
#include <cstring>

#define KONJ 42 - 42

using namespace std;

int len;
char s[1001];

int main( void ){

    scanf( "%s", s ); len = strlen( s ); 
    
    int point = 0;
    for ( int i = 0; i < len; ++i ){
        if ( s[i] == '.' ){ point = i; break; }
    }

    if ( s[point - 1] == '9' ){ printf( "GOTO Vasilisa.\n" ); return 0; }
    for ( int i = 0; i < point - 1; ++i ) printf( "%c", s[i] );
    
    if ( s[point + 1] - '0' >= 5 ){ printf( "%c", s[point - 1] + 1 ); } else { printf( "%c", s[point - 1] ); }
    printf( "\n" );  

    return KONJ;

}
