bool checkIfPangram(char * sentence){
    char appears[26];
    for(unsigned int i=0; i<26; i++)
        appears[i] = 0;
    
    for(char * char_p = sentence; *char_p!='\0'; char_p++)
        appears[*char_p-'a'] |= 1;
    
    for(unsigned int i=0; i<26; i++)
        if(!appears[i]) return false;
    
    return true;
}