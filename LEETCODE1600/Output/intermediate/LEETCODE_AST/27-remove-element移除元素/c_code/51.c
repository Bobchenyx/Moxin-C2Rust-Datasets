int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0) return 0;
    int i=0,j;
    for(j=0;j<numsSize;j++){
        if(nums[j]!=val){
            nums[i]=nums[j];
            i++;
        }
    }
    return i;

}