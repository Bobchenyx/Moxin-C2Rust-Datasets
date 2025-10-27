int minSubArrayLen(int s, int* nums, int numsSize){
    if (nums == NULL || numsSize == 0) {
        return 0;
    }

    int sum = 0;
    int left = 0;
    int right = 0;
    int min = 0xfffffff;
    
    while (right < numsSize && left <= right) {
        sum += nums[right];
        right++;
        while (sum >= s) {
            min = min <= (right - left) ? min : (right - left);
            sum -= nums[left++];         
        }
    }

    return min < 0xfffffff ? min : 0;
}