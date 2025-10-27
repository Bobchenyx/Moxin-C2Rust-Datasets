int removeElement(int* nums, int numsSize, int val){
    int cur = 0,i;

    for(i = 0;i < numsSize;i++){
        //skip the designative value
        if(nums[i] == val)
            continue;
        nums[cur++] = nums[i];
    }

    return cur;     
}