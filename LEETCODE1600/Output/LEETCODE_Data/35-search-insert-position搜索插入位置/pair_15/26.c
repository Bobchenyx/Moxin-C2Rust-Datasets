int searchInsert(int* nums, int numsSize, int target){
    if(numsSize == 0){
        return 0;
    }

    int i=0;
    for(; i< numsSize; i++){
        if(nums[i] >= target){
            return i;
        }
    }

    //此时所有数组元素遍历完毕，没有找到大于目标值的元素。那就插到最后
    return i;
}