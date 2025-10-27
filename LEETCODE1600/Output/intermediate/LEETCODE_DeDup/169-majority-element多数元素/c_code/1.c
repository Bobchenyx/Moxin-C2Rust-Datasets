int majorityElement(int* nums, int numsSize){

    int cnt = 0;
    int ret = nums[0];
    for(int i = 0; i < numsSize; i++)
    {
        if(ret == nums[i])
            cnt++;
        else
        {
            if(cnt <= 1)
            {
                ret = nums[i];
                cnt = 1;
            }
            else
            {
                cnt--;
            }
        }
        if(cnt > numsSize/2)
            break;
    }
    return ret;
}