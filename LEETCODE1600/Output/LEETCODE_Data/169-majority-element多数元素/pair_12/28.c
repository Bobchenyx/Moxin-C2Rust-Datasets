int majorityElement(int* nums, int numsSize){
    if(numsSize<1){
        return -1;
    }
    int result = nums[0],count=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i] == result){
            count++;
        }else{
            count--;
            if(count<0){
                result = nums[i];
                count = 1;
            }
        }
    }
    count = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] == result){
            count++;
        }
    }
    return (count>numsSize/2?result:-1);
}