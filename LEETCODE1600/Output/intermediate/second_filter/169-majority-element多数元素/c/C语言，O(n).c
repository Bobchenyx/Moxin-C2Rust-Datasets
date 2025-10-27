int majorityElement(int* nums, int numsSize){
    int cnt=1,tag=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(cnt==0){
            tag=nums[i];
            cnt=1;
        }
        else if(nums[i]==tag){
            cnt++;
        }
        else cnt--;
    }
    return tag;
}