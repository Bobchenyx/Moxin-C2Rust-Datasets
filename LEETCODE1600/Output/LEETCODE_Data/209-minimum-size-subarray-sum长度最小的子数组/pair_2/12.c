int min(int a, int b){
    return (a<b)?a:b;
}

int minSubArrayLen(int s, int* nums, int numsSize){
    int left = 0;
    int right = 0;
    int subSum = 0;
    int subLen = 0;

    while(right < numsSize){
        subSum += nums[right];
        if (subSum >= s){
            while((subSum - nums[left]) >= s){
                subSum -= nums[left];
                left++;
            }
            if (subLen == 0){
                subLen = right - left + 1;
            } else {
                subLen = min(subLen, right - left + 1);
            }
            
            if (subLen == 1){
                return subLen;
            }
        }
        right++;
    }
    return subLen;
1. }