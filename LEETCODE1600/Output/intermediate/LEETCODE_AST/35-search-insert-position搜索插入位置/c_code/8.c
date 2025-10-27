int searchInsert(int* nums, int numsSize, int target){
    int middle = 0,left = 0,right = numsSize-1;
    while(right-left>1){
        middle = (left+right)/2;
        if(nums[middle]<target)left = middle;
        else if(nums[middle]>target)right = middle;
        else break;
    }
    for(middle = left;middle<right+1;middle++)
        if(nums[middle]>=target)break;
    return middle;
}