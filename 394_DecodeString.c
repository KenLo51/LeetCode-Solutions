#define blockSize 32

typedef struct STRING{
	char *data;
	char *dataEnd;
	size_t size;
	size_t len;
}stringTypedef;
stringTypedef * createString(){
	stringTypedef * newString = (stringTypedef *) malloc(sizeof(stringTypedef));
	if(newString == NULL){
			return NULL;
	}
	newString->len  = 0;
	newString->size = blockSize;
	newString->data = (char *)malloc(sizeof(char) * (newString->size));
	newString->data[0] = '\0';
	newString->dataEnd = newString->data;
    return newString;
}
void stringAppend1c(stringTypedef *str, char ch){
	if(str->len+1 >= str->size){//not enough space
		char * newAddr = (char *)malloc(sizeof(char) * (str->size+blockSize));
		
		if(newAddr == NULL){
			free(str->data);
			free(str);
			return;
		}
		
		int i;
		for(i=0; i<str->len; i++){
			newAddr[i] = str->data[i];
		}
		newAddr[i] = '\0';
		free(str->data);
		str->data = newAddr;
		str->dataEnd = newAddr+i;
		
		str->size = str->size + blockSize;
	}
	*(str->dataEnd) = ch;
	str->dataEnd = str->dataEnd + 1;
	*(str->dataEnd) = '\0';
	str->len = str->len + 1;
}

#define CharIsNum(c) ((c>='0')&&(c<='9'))
#define CharIsLetter(c) ((c>='a')&&(c<='z'))

typedef struct BRACKET{
	unsigned int idx;
	unsigned short repeatTimes;//1<=k<=300
}bracketTypedef;

char * decodeString(char * s){
	stringTypedef * outStringObj = createString();
	bracketTypedef brackets[10];
	bracketTypedef* bracketsEnd = brackets;
	
	while(*s != '\0'){
		if(CharIsLetter(*s)){
			stringAppend1c(outStringObj, *s);
			
			s++;
		}
		
		else if(CharIsNum(*s)){
			bracketsEnd->repeatTimes = (*s++)-'0';
			while(CharIsNum(*s)){
				bracketsEnd->repeatTimes = bracketsEnd->repeatTimes*10 + (*s-'0');
				s++;
			}
			bracketsEnd->idx = outStringObj->len;
			bracketsEnd++;
			
			if(*s != '[')//invalid input
				return outStringObj->data;
			s++;
		}
		
		else if(*s == ']'){
			bracketsEnd--;
			int t;
			unsigned int repeatBeg, repeatEnd = outStringObj->len-1;
			for(t=1; t<bracketsEnd->repeatTimes; t++){//repeat k times
				for(repeatBeg = bracketsEnd->idx; repeatBeg<=repeatEnd; repeatBeg++){//copy string
					stringAppend1c(outStringObj, outStringObj->data[repeatBeg]);
				}
			}
			
			s++;
		}
	}
	return outStringObj->data;
}