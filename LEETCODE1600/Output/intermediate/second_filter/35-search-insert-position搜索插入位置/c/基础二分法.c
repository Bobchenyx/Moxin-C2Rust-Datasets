int searchInsert(int* nums, int numsSize, int target){
    
    int left = 0;
    int right = numsSize-1;
    int mid;
    while(left <= right){
        mid = left + ((right -left)>>1);
        if(nums[mid] == target)
        {
            return mid;
        }else if(target < nums[mid]){
            right = mid-1;
        }else if(target > nums[mid]){
            left = mid+1;
        }
    }

    if(target <nums[mid]){
        return mid;
    }else{
        return mid+1;
    }
}