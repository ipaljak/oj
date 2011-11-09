#include <cstdio>
#include <cstring>

#define KONJ 42 - 42
#define MAXN 1000010

using namespace std;

int len;
long long hash[MAXN], power[MAXN];

char s[MAXN];

bool check( int x ){

     for ( int i = 2; i + x <= len; ++i ){
    //     printf( "%lld %lld\n", hash[x] * power[i], hash[i + x - 1] - hash[i - 1] );
         if ( (long long) hash[x] * power[i] == ( long long ) hash[i + x - 1] - hash[i - 1] ) return true;
     }

     return false;

}

int main( void ){

    scanf( "%s", s ); len = strlen( s );
    hash[1] = s[0] - 'a'; power[1] = 1;
    
    for ( int i = 2; i <= len; ++i ){
        power[i] = power[i - 1] * 31;
        hash[i] = hash[i - 1] + power[i] * ( s[i - 1] - 'a' );
    }
    
    for ( int i = len - 2; i > 0; --i ){
        if ( hash[i] * power[len - i + 1] == hash[len] - hash[len - i] && check( i ) ){
           for ( int j = 0; j < i; ++j ) printf( "%c", s[j] );
           printf( "\n" ); return 0;
        } 
    }

    printf( "Just a legend\n" );

    return KONJ;

}
