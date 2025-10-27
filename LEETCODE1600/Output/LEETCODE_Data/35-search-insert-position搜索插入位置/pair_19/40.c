int searchInsert(int* nums, int numsSize, int target){

    if(target <= nums[0])
        return 0;
    if(target > nums[numsSize-1])
        return numsSize;
    
    int low = 0;
    int high = numsSize -1;
    int middle;
    while((high-low)>1)
    {
        middle = (low + high)/2;
        if(nums[middle] > target)
            high = middle;
        else if(nums[middle] < target)
            low = middle;
        else
            return middle;
    }
    return low+1;
}