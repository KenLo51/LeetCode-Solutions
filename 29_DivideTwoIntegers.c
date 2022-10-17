int divide(int dividend, int divisor){
    bool inv = (dividend<0) ^ (divisor<0);
    
    unsigned int quotient_u = 0;
    unsigned int dividend_u = (dividend > 0)? dividend : -(long)dividend;
    unsigned int divisor_u = (divisor > 0)? divisor : -(long)divisor;
    
    unsigned int products_u[32];
    products_u[0] = divisor_u;
    for(int i=1; i<32; i++){
        if(products_u[i-1] <= (UINT_MAX>>1))
            products_u[i] = products_u[i-1] + products_u[i-1];
        else
            products_u[i] = UINT_MAX;
    }
    
    for(int i=32-1; i>=0; i--){
        if(dividend_u >= products_u[i]){
            dividend_u = dividend_u - products_u[i];
            quotient_u |= (unsigned int)1<<(unsigned int)i;
        }
    }
    
    if(inv)
        return (quotient_u>INT_MAX-1)? INT_MIN : -(int)quotient_u;
    return (quotient_u>INT_MAX)? INT_MAX : quotient_u;
}