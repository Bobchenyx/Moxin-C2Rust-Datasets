int majorityElement(int* nums, int numsSize){
    int i = 0;
    int ret = nums[0];
    int retNum = 1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=ret){
            retNum -- ;
            if (retNum==0)
            {
                ret = nums[i];
                retNum++;
            }
        }
        else{
            retNum++;
        }
    }
    return ret;

}