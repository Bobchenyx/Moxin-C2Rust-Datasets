int maxSubArray(int* nums, int numsSize){
    int i,sum=0,max;
    max=nums[0];
    for(i=0;i<numsSize;i++){
        sum+=nums[i];
        if(sum>max) max=sum;
        if(sum<0) sum=0;
    }
    return max;
}