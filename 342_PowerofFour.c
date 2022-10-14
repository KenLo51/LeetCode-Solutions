#include <math.h>

bool isPowerOfFour(int n){
    if( n<=0 ) return false;
    float val = n;
    return  floor( 0.5*log2(val) ) == 0.5*log2(val);
}