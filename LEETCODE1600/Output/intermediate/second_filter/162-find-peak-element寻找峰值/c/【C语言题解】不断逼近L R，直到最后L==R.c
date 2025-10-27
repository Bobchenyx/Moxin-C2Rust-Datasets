int findPeakElement(int* nums, int numsSize){
    if(nums==NULL || numsSize==1) return 0;

    // 要求使用logN的时间复杂度，因此肯定是使用二分法
    int left = 0, right = numsSize-1, mid;

    while(left<right) {
        mid = (left + right) /2;

        if(nums[mid]>nums[mid+1]) {  // 找左边
            right = mid;
        }else if(nums[mid]<nums[mid+1]){  // 找右边
            left = mid+1;       
        }
    // printf("%d-%d\n",left,right);
    }
    mid = (left + right) /2;
    return mid;
}