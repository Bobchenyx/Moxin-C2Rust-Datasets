int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *count=(int *)malloc(sizeof(int)*(numsSize+1));
    memset(count,0,sizeof(int)*(numsSize+1));
    int *result=(int *)malloc(sizeof(int)*2);
    int i;
    for(i=0;i<numsSize;i++){
        count[nums[i]]++;
    }
    for(i=1;i<=numsSize;i++){
        if(count[i]==2)
            result[0]=i;
        if(count[i]==0)
            result[1]=i;
    }
    *returnSize=2;
    free(count);
    return result;
}