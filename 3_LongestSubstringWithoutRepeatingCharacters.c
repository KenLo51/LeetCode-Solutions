bool isUsedChar(uint64_t *charArr, char ch){
    return (charArr[ch/64] >> (ch%64))&1;
}
void addUsedChar(uint64_t *charArr, char ch){
    charArr[ch/64] |= (uint64_t)1<<(ch%64);
}
void clearUsedChar(uint64_t *charArr){
    charArr[0] = charArr[1] = 0;
}

int lengthOfLongestSubstring(char * s){
    int maxLen = 0;
    uint64_t usedCharData[2] = {0, 0};
    
    for(char* startChar = s; *startChar!='\0'; startChar++){
    	int currLen = 0;
    	for(char* stopChar = startChar; *stopChar!='\0'; stopChar++){
	        if(isUsedChar(usedCharData, *stopChar)){//with repeating characters
	            clearUsedChar(usedCharData);
	            break;
	        }
	        else{//without repeating characters
	            addUsedChar(usedCharData, *stopChar);
	            currLen++;
	        }
	    }
        if(currLen > maxLen)
            maxLen = currLen;
    }
    return maxLen;
}
