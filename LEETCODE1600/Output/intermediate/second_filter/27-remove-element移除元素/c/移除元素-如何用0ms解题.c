int removeElement(int* nums, int numsSize, int val){
    int i,j;
    int count=0;
    int temp;
    for(i=0;i<numsSize;i++)
        if(nums[i]==val)
            count++;
    int n=0;
    for(i=0;i<numsSize;i++)
    {
      
        if(nums[i]==val)
        {
            n++;
            if(n>count)
                break;//重点
            temp=nums[i];
            for(j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            nums[j]=temp;
            i--;//这里要减一个1，因为后一个数会到此处，我要在下一次继续判断
        }
    }
    return numsSize-count;//看说明
}