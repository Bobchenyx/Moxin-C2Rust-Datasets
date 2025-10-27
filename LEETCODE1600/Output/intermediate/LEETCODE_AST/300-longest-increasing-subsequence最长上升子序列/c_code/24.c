int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int *len=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        len[i]=1;
    }
    len[0]=1;int ml=0;
    for(int i=1;i<numsSize;i++){//代码关键部分，前面已经详解了
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]&&len[i]<len[j]+1){
                len[i]=len[j]+1;
            }
        }
    }
    int output=0;//输出len最大元素
    for(int i=0;i<numsSize;i++){
        if(len[i]>output){
            output=len[i];
        }
    }
    return output;
}