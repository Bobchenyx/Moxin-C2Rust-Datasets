int majorityElement(int* nums, int numsSize){
    int num = nums[0];
    int count = 0;
        for(int i = 0; i < numsSize; i++){
            if(num == nums[i])
                count++;
            else
                count--;    
            if(count <= 0)
                num = nums[i + 1];
        }
    return num;
}