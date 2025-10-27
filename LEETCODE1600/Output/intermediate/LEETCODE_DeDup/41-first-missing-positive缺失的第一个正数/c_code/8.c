int firstMissingPositive(int* nums, int numsSize){
    int mark = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == 1){
            mark = 1;
        }
        if(nums[i]<=0 || nums[i]>numsSize){
            nums[i] = 1;
        }
    }
    if(mark == 0){
        return 1;
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] < 0){
            if(nums[-nums[i]-1] > 0){
                nums[-nums[i]-1] = -nums[-nums[i]-1];
            }
        }else{
            if(nums[nums[i]-1] > 0){
                nums[nums[i]-1] = -nums[nums[i]-1];
            }
        }    
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] > 0){
            return i+1;
        }
    }
    return numsSize+1;
}