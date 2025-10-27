int findPeakElement(int* nums, int numsSize){
    if(numsSize<=0){
        return NULL;
    }
    if(numsSize==1){
        return 0;
    }
    if(numsSize==2){
        return nums[0]>nums[1]?0:1;
    }
    if(numsSize==3){
        if(nums[1]>nums[0]&&nums[1]>nums[2]){
            return 1;
        }
        return nums[0]>nums[2]?0:2;
    }
    if(nums[0]>nums[1]){
        return 0;
    }
    int temp;
    for(int i=1;i<numsSize-1;i++){
        if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
            temp = i;
            break;
        }
        if(i==numsSize-2){
            return numsSize-1;
        }
    }
    return temp;
}