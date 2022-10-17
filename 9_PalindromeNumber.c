bool isPalindrome(int x){
    char numStr[15];
    
    sprintf(numStr, "%d", x);
    
    int pRight = strlen(numStr)-1;
    int pLeft = 0;
    while(pLeft < pRight){
        if(numStr[pLeft] != numStr[pRight]) return false;
        
        pRight--;
        pLeft++;
    }
    
    return true;
}