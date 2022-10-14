
//#include <stdio.h>
int integerReplacement(int n){
    int numOp = 0;
    unsigned val = n;
    while(val != 1){
        numOp++;
        if((val % 2) == 0){ //even
            val = val >> 1;
        }
        else{ // odd
            if(val <= 3){
                val = val - 1;
            }
            else if(val & 0x02){ 
                val = val + 1;
            }
            else{
                val = val - 1;
            }
        }
    }
    return numOp;
}