int removeDuplicates(int* nums, int numsSize){
    int k = 0, j = 0;
    for(int  i = 0; i < numsSize; i++){
        for(j = 0; j < k; j++){
            if(nums[j] == nums[i]) break;
        }
        if(j == k) nums[k++] = nums[i];
    }
    return k;
}