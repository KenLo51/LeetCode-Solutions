

bool canConstruct(char * ransomNote, char * magazine){
    unsigned int amount[26] ;
    for(unsigned int i=0; i<26; i++)
        amount[i] = 0;
    
    for(; *magazine!='\0'; magazine++)
        amount[*magazine-'a']++;
    
    for(; *ransomNote!='\0'; ransomNote++){
        if(amount[*ransomNote-'a'] == 0) return false;
        amount[*ransomNote-'a']--;
    }
    return true;
}