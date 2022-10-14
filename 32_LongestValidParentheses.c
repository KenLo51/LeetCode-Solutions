//#include <stdio.h>
int longestValidParenthesesCb(char * s, int begIdx, int step, int endIdx){
    int parenthesesDeep = 0;
    int maxValidLen = 0;
    int validLen = 0;
    //printf(" ");
    for(int i=begIdx; i!=endIdx; i=i+step){
        //printf("%c", s[i]);
        if(s[i] == (step>0? '(':')')){
            parenthesesDeep = parenthesesDeep + 1;
            validLen = validLen + 1;
            continue;
        }
        if(s[i] == (step>0? ')':'(')){
            if(parenthesesDeep <= 0){//invalid
                parenthesesDeep = 0;
                validLen = 0;
            }
            else{//valid
                parenthesesDeep = parenthesesDeep - 1;
                validLen = validLen + 1;
                if(parenthesesDeep == 0)
                    if(maxValidLen < validLen) maxValidLen = validLen;
            }
            continue;
        }
    }
    return maxValidLen;
}
int longestValidParentheses(char * s){
    int strLen;
    for(strLen=0; s[strLen]!='\0'; strLen++);
    int validLen1 = longestValidParenthesesCb(s, 0, 1, strLen);
    int validLen2 = longestValidParenthesesCb(s, strLen-1, -1, -1);
    //printf("\n%d-%d\n", validLen1,validLen2);
    return validLen1>validLen2? validLen1:validLen2;
}