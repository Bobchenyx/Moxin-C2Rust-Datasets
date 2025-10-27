int findRepeatNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize;) {
        if(nums[i] == i) {
            i++;
        }
        else {
            int m = nums[i];
            if(m == nums[m]) {
                return m;
            }
            else {
                nums[i] = nums[m];
                nums[m] = m;
            }
        }
    }
    // 必须有一个一定能执行的返回语句，不然会报错
    return -1;
}