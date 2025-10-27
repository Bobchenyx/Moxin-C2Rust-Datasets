int cmp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int majorityElement(int* nums, int numsSize){

int res=0;
qsort(nums,numsSize,sizeof(nums[0]),cmp);
int cur_size=0,max_size=0;
int prev=nums[0];

for(int i=0;i<numsSize;i++)
{
    if(prev==nums[i])
      cur_size++;
    else 
    {
      prev=nums[i];
      cur_size=1;
    }

    if(cur_size==max_size)
      res=prev;
    else if(cur_size>max_size)
    {
        max_size=cur_size;
        res=prev;
    }
}
return res;
}