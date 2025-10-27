int removeElement(int* nums, int numsSize, int val){
     int i=0,len=-1;
     if(numsSize!=0){
         for(i=0;i<numsSize;i++){
             if(nums[i]!=val)
                nums[++len]=nums[i];
        }
     }
     len++;
     return len;
}