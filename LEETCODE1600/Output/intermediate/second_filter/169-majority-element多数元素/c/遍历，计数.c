int majorityElement(int* nums, int numsSize){
    int count=0;
    int current=0;
    for(int i=0;i<numsSize;i++){
        if(count>0){
            if(current==nums[i]) count++;
            else count--;
        }else{
            current=nums[i];
            count++;
        }
    }
    return current;
}