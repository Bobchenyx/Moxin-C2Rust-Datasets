int max(int a,int b){
    return a>b? a:b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int j,i,count = 0,maxCount = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=0)
           count++;
        else{
           maxCount = max(count,maxCount);
           count = 0;
        }
    }
    return maxCount = max(count,maxCount);
}