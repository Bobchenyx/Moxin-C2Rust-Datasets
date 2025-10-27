int removeDuplicates(int* nums, int numsSize){
    for(int i=0;i<numsSize-1;i++)
    {
        while(nums[i]==nums[i+1]&&i+1!=numsSize)
        {
            
            for(int j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
          numsSize--;
        } 
         
    }
    return numsSize;

}