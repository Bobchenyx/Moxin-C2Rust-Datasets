int removeElement(int* nums, int numsSize, int val){
int i,j;
if(numsSize==0)
return 0;
if(numsSize==1&&val==nums[0])
return 0;
if(numsSize==1&&val!=nums[0])
return 1;
for(i=0;i<numsSize-1;i++)
    if(nums[i]==val)//shift left
    {
        for(j=i;j<numsSize-1;j++)
        {
            nums[j]=nums[j+1];
        }
        numsSize--;
        i--;
    }
if(nums[numsSize-1]==val)
    numsSize--;
return numsSize;
}