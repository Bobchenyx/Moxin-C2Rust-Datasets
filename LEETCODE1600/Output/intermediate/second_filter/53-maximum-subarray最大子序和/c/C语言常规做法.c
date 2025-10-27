int maxSubArray(int* nums, int numsSize){
    int i=0,maxSum=-2147483647,currentSum=0;
    while(i<numsSize){
        currentSum+=nums[i++];
        if(currentSum>maxSum) maxSum=currentSum;
        if(currentSum<0) currentSum=0;
    }
    return maxSum;
}