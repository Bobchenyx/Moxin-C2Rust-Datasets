int removeElement(int* nums, int numsSize, int val){
    int size=numsSize;
    for(int i=0;i<size;)
    {
        if(nums[i]==val)
        {
            for(int j=i;j<numsSize-1;j++)
            {
                nums[j]=nums[j+1];
            }
            size--;
        }
        else i++;
    }
    return size;
}