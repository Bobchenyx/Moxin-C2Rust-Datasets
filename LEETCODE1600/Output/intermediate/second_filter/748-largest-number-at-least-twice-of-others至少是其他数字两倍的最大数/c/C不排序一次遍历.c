int dominantIndex(int* nums, int numsSize){
    if(numsSize==1) return 0;
    int max=0,secmax=0,maxindex=0;
    int i;
    for(i=0;i<numsSize;i++){
        if(nums[i]>max){//更新最大
            secmax=max;
            maxindex=i;
            max=nums[i];
        }else if(nums[i]>secmax){//更新次大
            secmax=nums[i];
        }
    }
    if(max<2*secmax)
        return -1;
    return maxindex;

}