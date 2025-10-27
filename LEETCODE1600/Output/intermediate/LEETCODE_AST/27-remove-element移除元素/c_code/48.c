int removeElement(int* nums, int numsSize, int val){
   int count=numsSize,m=0,n=0;
   for(m=0;m<numsSize;m++){
       if(nums[m]!=val){
        nums[n]=nums[m];
        n++;   
       } 
       else count--;
   }
    return count;
}