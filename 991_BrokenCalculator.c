//#include <stdio.h>
int brokenCalc(int startValue, int target){
    int doubleNum = 0;
    while(startValue < target){
        doubleNum = doubleNum + 1;
        startValue = startValue * 2;
    }
    int decrementNum = 0;
    while(startValue > target){
        decrementNum = decrementNum + 1;
        startValue = startValue - 1;
    }
    
    int temp = decrementNum;
    decrementNum = 0;
    for(int i=0; i<doubleNum; i++){
        decrementNum += temp % 2;
        temp = temp / 2;
    }
    decrementNum += temp;
    
    //printf("%d, %d", doubleNum, decrementNum);
    return doubleNum + decrementNum;
}