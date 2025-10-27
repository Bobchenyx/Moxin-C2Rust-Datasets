int removeElement(int* nums, int numsSize, int val){
    int i,j;
    for(i=0;i<numsSize;++i){
        if(nums[i]==val){
            for(j=i;j<numsSize-1;j++){
                nums[j]=nums[j+1];

            }
            numsSize-=1;
            --i;//第一轮写错了位置导致了死循环
        } 
      
    }
    return numsSize;
}