int judge(int *A, int len){
    for(int i=0;i<len-1;i++){
        if(A[i]<=A[i+1]){
            continue;
        }
        else
            return 0;
    }
    return 1;
}


bool checkPossibility(int* nums, int numsSize){
    int MIN=-32767;
    if(numsSize==1)
        return true;
    int i=0;
    int *tmp=(int *)calloc(numsSize,sizeof(int));
    for(i;i<numsSize;i++){
        memcpy(tmp, nums, sizeof(int)*numsSize);
        if(i==0)
            tmp[0]=MIN;
        else tmp[i]=tmp[i-1];
        if(judge(tmp,numsSize)==1)
            return true;
        else{
            continue;
        }
    }
    return false;
}