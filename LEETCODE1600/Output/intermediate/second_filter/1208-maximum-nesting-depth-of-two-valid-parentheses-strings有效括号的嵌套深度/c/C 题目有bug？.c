int* maxDepthAfterSplit(char * seq, int* returnSize){
    int len = strlen(seq);
    if (len == 0) {
        *returnSize = len;
        return seq;
    }
    #if 0
    int *stack = (int *)malloc(len * sizeof(int)); 
    int maxDep = 0;
    int curDep = 0;
    int stackRear = 0;
    for (int i = 0; i < strlen(seq); ++i) {
        if (seq[i] == '(') {
            stack[stackRear++] = seq[i];
        } else {
            stackRear--;
            curDep++;
            if (stackRear == 0) {
                maxDep = (maxDep >= curDep) ? maxDep : curDep;
                curDep = 0;
            }
        }
    }
    free(stack);
    #endif
   // printf("maxDepth %d\n", maxDep);
   int *ans = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            ans[i] = (seq[i] == '(') ? 0 : 1;
        } else {
            ans[i] = (seq[i] == ')') ? 0 : 1;
        }
    }
    *returnSize = len;
    return ans;
}