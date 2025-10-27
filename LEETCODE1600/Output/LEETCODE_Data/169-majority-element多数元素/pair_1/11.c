int majorityElement(int* nums, int numsSize){
    int num = nums[0],count = 1;
    for(int i = 1; i < numsSize; i++){
        if(num==nums[i]){
            count++;
        }else if(count>0){
            count--;
        }else{
            num=nums[i];
            count=1;
        }
    }
    if(count==0)
        return -1;
    int n = 0;
    for(int i = 0; i < numsSize; i++){
        if(num==nums[i])
            n++;
    }
    if(n >= numsSize/2)
        return num;
    else
        return -1;
        
}