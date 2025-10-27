int searchInsert(int* nums, int numsSize, int target){
    int low=0;
    int high=numsSize-1;
    int middle=0;

    while(low <= high){
        middle=low+(high-low)/2;
        if(target>nums[middle]){
            low=middle+1;
        }else if (target<nums[middle]){
                high=middle-1;
        }
            else if(target==nums[middle]){
                return middle;
            }
               
    }
    return low;
}