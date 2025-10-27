int majorityElement(int* nums, int numsSize){

if(numsSize==0) return 0;
int cnt=0,major=0;

for(int i=0;i<numsSize;i++)
{
    if(cnt==0)
    {
        major=nums[i];
        cnt++;
        continue;
    }
    if(nums[i]==major)
    {
        cnt++;
        continue;
    }  
    cnt--;
}
return major;
}