int removeDuplicates(int* nums, int numsSize){
   if(numsSize==0)
   {
       return 0;
   }
   int cnt=1;
   for(int i=0;i<numsSize-1;i++)
   {
       if(nums[i+1]!=nums[i])
       {
           nums[cnt++]=nums[i+1];
       }
   }
   return cnt;
}