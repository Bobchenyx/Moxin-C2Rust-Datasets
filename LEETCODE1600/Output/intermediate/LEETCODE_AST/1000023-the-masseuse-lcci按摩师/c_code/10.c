int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    else if(numsSize == 1)
        return nums[0];
    else if(numsSize == 2)
        return (nums[0] > nums[1] ? nums[0] : nums[1]);
    int i, current, memorize[3];
    memorize[0] = (numsSize > 0 ? nums[0] : 0);
    memorize[1] = (numsSize > 1 ? nums[1] : 0);
    memorize[2] = (numsSize > 2 ? nums[2] + nums[0] : 0);
    current = memorize[2];
    for(i = 3;i < numsSize;i ++){
        current = nums[i] + (memorize[0] > memorize[1] ? memorize[0] : memorize[1]);
        memorize[0] = memorize[1];
        memorize[1] = memorize[2];
        memorize[2] = current;
    }
    return (memorize[1] > memorize[2] ? memorize[1] : memorize[2]);
}