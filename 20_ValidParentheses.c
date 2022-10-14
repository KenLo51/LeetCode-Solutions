
#define isOpenBracket(c) ((c)=='(' || (c)=='{' || (c)=='[')
#define isCloseBracket(c) ((c)==')' || (c)=='}' || (c)==']')
bool isValid(char * s){
    //get string size
    size_t strLen;
    for(strLen=0; s[strLen]!='\0'; strLen++);
    
    //create stack
    char *bracketStack = (char *)malloc(strLen);
    char *bracketStackTop = bracketStack-1;
    
    char *currChar;
    for(currChar=s; *currChar!='\0'; currChar++){
        if(isOpenBracket(*currChar)){
            //push to stack
            *(++bracketStackTop) = *currChar;
        }
        if(isCloseBracket(*currChar)){
            //pop from stack
            if(bracketStackTop < bracketStack) return false;
            char pop = *(bracketStackTop--);
            
            //check type
            if(isCloseBracket(pop)) return false;
            if((*currChar)==')' && pop!='(') return false;
            if((*currChar)==']' && pop!='[') return false;
            if((*currChar)=='}' && pop!='{') return false;
        }
    }
    if(bracketStackTop >= bracketStack) return false;
    return true;
}