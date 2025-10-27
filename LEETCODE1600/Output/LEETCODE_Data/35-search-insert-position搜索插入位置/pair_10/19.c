int searchInsert(int* nums, int numsSize, int target){
    int low = 0;
    int high = numsSize - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (target > nums[mid])
        {
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else if (target == nums[mid])
        {
            return mid;
        }
    }

    return low;
}