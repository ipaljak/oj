#include <cstdio>
#include <cstring>
#include <algorithm>

#define KONJ 42 - 42
#define INF 1000000000

using namespace std;

int N, K, sol = INF;

char mat[9][9];
char mat1[9][9];

bool bio[9];

void solve( int curr ){

     if ( curr == K ){
        int maks = -1, mini = INF;
        //printf( "\n" );
        for ( int i = 0; i < N; ++i ){
            int tmp;
            sscanf( mat1[i], "%d", &tmp );
            //printf( "%d\n", tmp );
            maks = max( tmp, maks ); mini = min( mini, tmp );
        }
        sol = min( sol, maks - mini );
        return;
     }
     
     for ( int i = 0; i < K; ++i ){
         
         if ( bio[i] ) continue;
         
         bio[i] = true;
         for ( int j = 0; j < N; ++j ) mat1[j][curr] = mat[j][i];
         
         solve( curr + 1 );
         bio[i] = false;
         
     }
     
}
     
int main( void ){

    scanf( "%d%d", &N, &K );
    for ( int i = 0; i < N; ++i ) scanf( "%s", mat[i] ); 

    solve( 0 );
    printf( "%d\n", sol );

    return KONJ;

}
