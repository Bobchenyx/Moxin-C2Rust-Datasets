int maxSubArray(int* nums, int numsSize){
    int maxsum = 0;
    int thissum = 0;
    int i = 0, maxitem=nums[0];


    /*全负数时，下面公式cover不了，单独处理*/
    for(i=0; i<numsSize; i++){
        maxitem = maxitem > nums[i] ? maxitem : nums[i];
    }

    if(maxitem < 0)
        return maxitem;

    for(i=0; i<numsSize; i++){
        thissum += nums[i];
        /*
        连续子序列只要是正数，就有用要加上来
        连续子序列只要是负数，就利害要抛弃掉
        */
        if(thissum < 0)
            thissum = 0;
        else if(thissum > maxsum)
            maxsum = thissum;
        
    }
    return maxsum;
}