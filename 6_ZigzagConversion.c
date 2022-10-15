char * convert(char * s, int numRows){
    if(numRows == 1) return s;
    
    unsigned int sLen;
    for(sLen=0; s[sLen]!='\0'; sLen++);
    
    char* res = (char*)malloc(sLen+1);
    unsigned int resIdx = 0;
    
    unsigned int step = (numRows-1)*2;
    // row-0
    for(unsigned int i=0; i<sLen; i+=step)
        res[resIdx++] = s[i];
    
    // row-1 ~ row-(n-2)
    for(unsigned int rowIdx=1; rowIdx<numRows-1; rowIdx++){
        unsigned int i=rowIdx;
        while(1){
        	if(i>=sLen) break;
            res[resIdx++] = s[i];
            i += step-rowIdx*2;
            if(i>=sLen) break;
            res[resIdx++] = s[i];
            i += rowIdx*2;
        }
    }
    
    // row-(n-1)
    for(unsigned int i=numRows-1; i<sLen; i+=step)
        res[resIdx++] = s[i];
        
    res[resIdx++] = '\0';
    
    return res;
}
