int majorityElement(int* nums, int numsSize){
    int candi = nums[0];
    int cnt = 1;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] == candi)
        {
            cnt++;
        }
        else if(cnt > 0)
        {
            cnt--;
        }
        else
        {
            candi=nums[i];
            cnt=1;
        }
    }
    return candi;
}