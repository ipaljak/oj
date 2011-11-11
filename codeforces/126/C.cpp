#include <cstdio>

#define KONJ 42 - 42
#define MAXN 2010

using namespace std;

int N;
int uprow[MAXN], upcol[MAXN], downrow[MAXN], downcol[MAXN];

char grid[MAXN][MAXN];

int main( void ){

    scanf( "%d", &N );
    for ( int i = 0; i < N; ++i ) scanf( "%s", grid[i] );
    
    int sol = 0;
    
    for ( int i = N - 1; i >= 0; --i ){
        for ( int j = 0; j < i; ++j ){
            bool press = ( downrow[i] + downcol[j] + ( grid[i][j] - '0' ) ) % 2;
            if ( press ){ ++sol; ++downcol[j]; ++downrow[i]; } 
        }
    }
    
    for ( int i = 0; i < N; ++i ){
        for ( int j = N - 1; j > i; --j ){
            bool press = ( uprow[i] + upcol[j] + ( grid[i][j] - '0' ) ) % 2;
            if ( press ){ ++sol; ++upcol[j]; ++uprow[i]; } 
        
        }
    }
    
    for ( int i = 0; i < N; ++i ){
        bool press = ( uprow[i] + upcol[i] + ( grid[i][i] - '0' ) + downrow[i] + downcol[i] ) % 2;
        if ( press ){ ++sol; } 
    }
    
    printf( "%d\n", sol );
    
    return KONJ;

}
