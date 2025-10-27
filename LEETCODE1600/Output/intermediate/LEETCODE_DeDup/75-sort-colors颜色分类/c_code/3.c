void sortColors(int* nums, int numsSize){
    int i=0,j=numsSize-1,k=0,temp=0;
    while(k<=j)//这里一定要加=  2 0 1 这种情况可以解释原因
    {
        if(nums[k]==1)
           k+=1;
        else if(nums[k]==0)
        {
           temp=nums[i];
           nums[i]=nums[k];
           nums[k]=temp;
           i+=1;
           k+=1;
        }
        else{
          temp=nums[j];
           nums[j]=nums[k];
           nums[k]=temp;
           j-=1;
        }
    }

}