

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//#include <stdio.h>
int* partitionLabels(char * s, int* returnSize){
    int firstIdx[26];
    int lastIdx[26];
    int idxTable[26];
    for(int i=0; i<26; i++)
        idxTable[i] = firstIdx[i] = lastIdx[i] = -1;
    
    int sIdx;
    int idxTableCounter = -1;
    for(sIdx = 0; s[sIdx] != '\0'; sIdx++){
        char currChar = s[sIdx];
        if(idxTable[currChar-'a'] == -1){
            idxTableCounter = idxTableCounter + 1;
            idxTable[currChar-'a'] = idxTableCounter;
        }
        int dataIdx = idxTable[currChar-'a'];
        if(firstIdx[dataIdx] == -1){//new charactor
            firstIdx[dataIdx] = sIdx;
        }
    }
    for(sIdx = sIdx - 1; sIdx>=0; sIdx--){
        char currChar = s[sIdx];
        int dataIdx = idxTable[currChar-'a'];
        if(lastIdx[dataIdx] == -1){//new charactor
            lastIdx[dataIdx] = sIdx;
        }
    }
    
    /*for(int i=0; i<26; i++)
        printf("%d, ", firstIdx[i]);
    printf("\n");
    for(int i=0; i<26; i++)
        printf("%d, ", lastIdx[i]);
    printf("\n");*/
    
    int *outputArr = (int *)malloc(26*sizeof(int));
    int outputArrSize = 0;
    
    int startPartIdx = 0;
    int endPartIdx = 0;
    int semaphore = 0;
    for(int i=0; i<26; i++){
        if(firstIdx[i] == -1)
            break;
        int dataIdx = i;
        if(endPartIdx < firstIdx[dataIdx]){
            //printf("%d-%d, ", startPartIdx, endPartIdx);
            //printf("%d, ", endPartIdx - startPartIdx + 1);
            outputArr[outputArrSize++] = endPartIdx - startPartIdx + 1;
            startPartIdx = endPartIdx+1;
            endPartIdx = lastIdx[dataIdx];
        }
        else if(endPartIdx < lastIdx[dataIdx]){
            endPartIdx = lastIdx[dataIdx];
        }
        //printf("%d-%d, ", startPartIdx, endPartIdx);
    }
    //printf("%d, ", endPartIdx - startPartIdx + 1);
    outputArr[outputArrSize++] = endPartIdx - startPartIdx + 1;
    *returnSize = outputArrSize;
    return outputArr;
}