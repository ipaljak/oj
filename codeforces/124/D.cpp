#include <cstdio>
#include <algorithm>

#define KONJ 42 - 42

using namespace std;

int A, B, x1, y1, x2, y2;

int main( void ){
    
    scanf( "%d%d%d%d%d%d", &A, &B, &x1, &y1, &x2, &y2 );
    
    int X1 = x1 + y1, Y1 = x1 - y1;
    int X2 = x2 + y2, Y2 = x2 - y2;
    
    if ( X1 > 0 ){ X1 /= 2 * A; } else { X1 /= 2 * A; --X1; }
    if ( X2 > 0 ){ X2 /= 2 * A; } else { X2 /= 2 * A; --X2; }
    
    if ( Y1 > 0 ){ Y1 /= 2 * B; } else { Y1 /= 2 * B; --Y1; }
    if ( Y2 > 0 ){ Y2 /= 2 * B; } else { Y2 /= 2 * B; --Y2; }
       
    printf( "%d\n", max( abs( X1 - X2 ), abs( Y1 - Y2 ) ) );

    return KONJ;

}
