

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	int* readPtr = pushed;
	int* stackPtr = pushed;
	int* stackTop = pushed-1;
	
	int* wantedVal = popped;
	
	for(int i=0; i<pushedSize; i++){
		stackTop++;
		*stackTop = *readPtr;
		readPtr++;
		while(*stackTop == *wantedVal){
			wantedVal++;
			stackTop--;
			
			if( (wantedVal-popped) >= poppedSize ) return true;
			if(stackTop < stackPtr) break;
		}
	}
	return false;
}