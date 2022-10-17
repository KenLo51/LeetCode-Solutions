double myPow(double x, int n){
    if(n == 0) return 1;
    bool inv = n<0;
    long val = n;
    if(inv) val = -val;
    
    int div2 = val / 2;
    double div2Pow = myPow(x, div2);
    double res = div2Pow * div2Pow;
    if((val%2) != 0) res = res * (double)x;
    
    if(inv) res = 1/res;
    return res;
}