int dominantIndex(int* nums, int numsSize){
    short max=nums[0],max_index=0,max_2nd=0,i;
    for(i=0;i<numsSize;i++)
        if(nums[i]>max){
            max=nums[i];
            max_index=i;
        }
    for(i=0;i<numsSize;i++)
        if(nums[i]<max&&nums[i]>max_2nd) max_2nd=nums[i];
    if(max>=max_2nd*2) return max_index;
    else return -1;
}