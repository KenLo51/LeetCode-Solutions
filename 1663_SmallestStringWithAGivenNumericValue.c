
char * getSmallestString(int n, int k){
    char *str = (char*)malloc(n+1);
    str[n] = '\0';
    int charIdx;
    for(int i=n-1; i>=0; i--){
        charIdx = k - i;
        charIdx = (charIdx>=26)? 26 : charIdx;
        str[i] = charIdx - 1 + 'a';
        k = k - charIdx;
    }
    return str;
}