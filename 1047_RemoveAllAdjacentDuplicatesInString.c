char * removeDuplicates(char * s){
    char* src = s+1;
    char* dst = s+1;
    for(src = s+1; *src!='\0'; src++){
        if(dst == s){//output string is empty
            *dst = *src;
            dst++;
            continue;
        }
        
        if(*(dst-1) == *src){//adjacent and equal
            while(*(dst-1) == *src){
                dst = dst - 1;//remove lastest char in output string
                if(dst == s)//output string is empty
                    break;
            }
            continue;
        }

        //put the new char
        *dst = *src;
        dst++;
    }
    *dst = '\0';
    return s;
}