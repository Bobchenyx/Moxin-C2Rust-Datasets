int majorityElement(int* nums, int numsSize){
    int count=1,can=nums[0];
    for(int i=1;i<numsSize;i++){
        if(can==nums[i]){
            count++;
        }else{
            count--;
            if(count<0){
                can=nums[i];
                count=1;
            }
        }
    
    }
    return can;
}