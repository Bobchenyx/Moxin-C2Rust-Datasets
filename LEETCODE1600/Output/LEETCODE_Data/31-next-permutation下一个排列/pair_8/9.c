void nextPermutation(int* nums, int numsSize){
    if(numsSize < 2){
        return;
    }
    int i=numsSize-1,j=numsSize-1;
    while(i>0){
        if(nums[i] > nums[--i]){
            break;
        }
    }
    if(i==0 && nums[i]>=nums[i+1]){             //1.
        for(i=0,j=numsSize-1;i<j;i++,j--){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        } 
    }else{                                       //2.
        for(j=numsSize-1;nums[j]<=nums[i];j--);
        int temp = nums[i];
        nums[i++] = nums[j];
        nums[j] = temp;
        for(i,j=numsSize-1;i<j;i++,j--){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}