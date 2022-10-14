int scoreOfParenthesesRec(char * s, char ** s_return){
    int score = 0;
    for(char *c = s; *c != '\0'; c++){
        if(*c == '(')
            score += scoreOfParenthesesRec(c+1, &c);
        else if(*c == ')'){
            *s_return = c;
            if(score == 0) return 1;
            return score*2;
        }
    }
    return score;
}
int scoreOfParentheses(char * s){
    int score = 0;
    char * end;
    score = scoreOfParenthesesRec(s, &end);
    return score;
}

