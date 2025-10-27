int findLengthOfLCIS(int* nums, int numsSize){
    if(numsSize<2)
        return numsSize;
    int cnt=1,t=nums[0],max=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]>t){
            cnt++;
            t=nums[i];
        }
        else{
            max=max>cnt?max:cnt;
            cnt=1;
            t=nums[i];
        }
    }
    return max>cnt?max:cnt;
}