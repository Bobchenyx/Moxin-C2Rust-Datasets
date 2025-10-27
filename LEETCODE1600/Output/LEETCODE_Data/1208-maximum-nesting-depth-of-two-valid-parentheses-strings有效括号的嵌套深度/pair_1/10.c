int* maxDepthAfterSplit(char * seq, int* returnSize){
    *returnSize = strlen(seq);
    int continueFlag = 1;
    int *allocate = (int *)malloc((*returnSize)*sizeof(int));
    for(int seqIndex = 0; seqIndex < (*returnSize); seqIndex++){
        allocate[seqIndex] = (seq[seqIndex] == '(')?((continueFlag == 1)?0:1):((continueFlag == 0)?0:1);
        continueFlag = (continueFlag == 1)?0:1;
    }
    return allocate;
}