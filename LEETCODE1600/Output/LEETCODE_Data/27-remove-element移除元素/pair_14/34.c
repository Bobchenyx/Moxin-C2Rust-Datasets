int removeElement(int* nums, int numsSize, int val){
    int tail = -1;
    int i = 0;
    int ret = 0;
    bool isRemove = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] != val){
            tail++;
            ret++;
            if(isRemove){
                nums[tail] = nums[i];
            }
        }else{
            isRemove = 1;
        }
    }
    return ret;
}