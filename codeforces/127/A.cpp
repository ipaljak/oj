#include <cstdio>
#include <cmath>

#define KONJ 42 - 42 

using namespace std;

int N, K;

double dist( double x1, double y1, double x2, double y2 ){
       return sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
}

int main( void ){

    scanf( "%d%d", &N, &K );
    
    double sol = 0, px, py, cx, cy;
    scanf( "%lf %lf", &px, &py );
    
    for ( int i = 1; i < N; ++i ){
        scanf( "%lf%lf", &cx, &cy );
        sol += dist( px, py, cx, cy );
        px = cx; py = cy;
    }
    
    printf( "%.7lf\n", (double) K * sol / 50.0 );

    return KONJ;

}
