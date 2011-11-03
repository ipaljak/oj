#include <cstdio>
#include <cstring>
#include <algorithm>

#define KONJ 42 - 42

using namespace std;

int len, zn;
int slovo[27];

char s[1010], sol[1010];
bool bio[1010];

bool prime( int x ){
     
     if ( x == 1 ) return false;
     
     for ( int i = 2; i * i <= x; ++i ){
         if ( x % i == 0 ) return false;
     }
     
     return true;
     
}

int main( void ){

    scanf( "%s", s ); len = strlen( s );
    for ( int i = 0; i < len; ++i ) ++slovo[ s[i] - 'a' ];
    
    int jebeno = 0;
    for ( int i = 0; i < 26; ++i ){
        jebeno = max( jebeno, slovo[i] );
        if ( jebeno == slovo[i] ) zn = i;
    }

    int cnt = len - 1;
    for ( int i = len / 2 + 1; i <= len; ++i ){
        if ( prime( i ) ) --cnt;
    }
    
    //printf( "%d\n", jebeno );
    if ( cnt > jebeno ){ printf( "NO\n" ); return 0; }

    for ( int i = 1; i < len; ++i ){
        if ( i + 1 <= len / 2 || !prime( i + 1 ) ){ sol[i] = zn + 'a'; bio[i] = true; --jebeno; continue; }
    }

    for ( int i = 0; i < len; ++i ){
        if ( bio[i] ) continue;
        for ( int j = 0; j < len; ++j ){
            if ( s[j] == zn + 'a' && jebeno > 0 ){ sol[i] = s[j]; --jebeno; break; }
            if ( s[j] != zn + 'a' ){ sol[i] = s[j]; s[j] = zn + 'a'; break; }
        }
    }

    printf( "YES\n" );
    printf( "%s\n", sol );

    return KONJ;

}
