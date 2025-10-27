int findMaxConsecutiveOnes(int* nums, int numsSize){
    int count=0;
    int now=0;
    int i=0;
    while(i<numsSize){
        if(nums[i]==0){
            i++;
        }
        else{
            now=0;
            while(i<numsSize&&nums[i]==1){
                i++;
                now++;
            }
            if(now>count){
                count=now;
            }
        }
    }
    return count;
}