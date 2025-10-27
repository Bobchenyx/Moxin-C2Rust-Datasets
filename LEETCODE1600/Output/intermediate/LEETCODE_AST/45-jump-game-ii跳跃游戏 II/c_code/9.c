int jump(int* nums, int numsSize){
    int current_max_index = nums[0];
    int pre_max_index = nums[0];
    int jump_step = 1;
    if(numsSize < 2)
        return 0;
    for(int i = 1; i < numsSize; i++){
        if(i > current_max_index){
            jump_step++;
            current_max_index = pre_max_index;
        }
        if(nums[i] + i > pre_max_index){
            pre_max_index = nums[i] + i;
        }
    }
    return jump_step;
}