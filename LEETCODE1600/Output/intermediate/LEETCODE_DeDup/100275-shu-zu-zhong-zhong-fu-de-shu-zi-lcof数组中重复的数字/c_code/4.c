int findRepeatNumber(int* nums, int numsSize){
    int hash[100000] = {0};

    int i;
    for(i = 0;i < numsSize;i++){
        if(hash[nums[i]] == 0){
            hash[nums[i]] = 1;
        }
        else{
            return nums[i];
        }
    }

    return 0;

}