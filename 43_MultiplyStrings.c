char * multiply(char * num1, char * num2){
    // get string length
    unsigned int num1Size, num2Size;
    for(num1Size = 0; num1[num1Size] != '\0'; num1Size++);
    for(num2Size = 0; num2[num2Size] != '\0'; num2Size++);
//          num1
//      x)  num2
//     -----------
//   num1 x num2[0]
//  num1 x num2[1]
// ...

    // init sum string
    unsigned char sum[400];
    for(unsigned int i=0; i<400; i++) sum[i] = 0;

    // Multiply each row
    for(unsigned int i=0; i<num2Size; i++){
        unsigned int currDigitOffset;
        unsigned char carryOut = 0;
        for(unsigned int j=0; j<num1Size; j++){
            currDigitOffset = 399 - (i + j);

            //          product   =     num1        *      num2       + carryOut
            unsigned char product = (num2[num2Size-i-1] - '0') * (num1[num1Size-j-1] - '0')
                 + carryOut + sum[currDigitOffset];
            // 
            carryOut = product / 10;
            sum[currDigitOffset] = product % 10;
        }
        sum[--currDigitOffset] = carryOut % 10;
    }

    // copy to resoult 
    char* resStr = (char*)malloc(400);
    unsigned int srcPtr = 0;
    unsigned int dstPtr = 0;
    // skip '0', reserve last '0'
    while(sum[srcPtr] == 0){
        srcPtr = srcPtr + 1;
        if(srcPtr >= (400-1)) break;
    }
    // copy number
    while(srcPtr < 400){
        // copy number and transform uint to char
        resStr[dstPtr] = sum[srcPtr] + '0';
        // next char
        dstPtr = dstPtr + 1;
        srcPtr = srcPtr + 1;
    }
    // put '\0' after string
    resStr[dstPtr++] = '\0';
    return resStr;
}