//折半查找法
int searchInsert(int* nums, int numsSize, int target){
    int a=0, b=numsSize-1, mid;
    while(a <= b){
        mid = (a + b) / 2;
        if(target > nums[mid])
            a = mid + 1;
        else if(target < nums[mid])
            b = mid - 1;
        else return mid;
    }
    return target<nums[mid] ? mid : mid + 1;
}