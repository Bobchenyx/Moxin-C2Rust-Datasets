int firstMissingPositive(int* nums, int numsSize){
    int min = 1;
    int i = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i]==min){
            min++;
            i = -1;
        }
    }
    return min;
}