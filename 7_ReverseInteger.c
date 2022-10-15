int reverse(int x){
    int res=0;
    for(unsigned int y=(x>0)? x:-(long)x; y>0; y/=10){
        if(res > INT_MAX/10) return 0;
        res = res*10 + y%10;
    }
    return (x>0)? res:-res;
}