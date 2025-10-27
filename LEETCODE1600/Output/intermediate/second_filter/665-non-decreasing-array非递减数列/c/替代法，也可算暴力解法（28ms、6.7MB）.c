bool checkPossibility(int* nums, int numsSize){
    int x=0,i=0;
    while(x<2 && i<numsSize-1){
        if(nums[i]>nums[i+1]){
            int temp1=nums[i];
            int temp2=nums[i+1];
            
            nums[i]=temp2;
            if(i>0&&nums[i-1]>nums[i]){
                nums[i+1]=temp1;
                nums[i]=temp1;
            }
            x++;
        }
            
            i++;

    }
    if(x>=2) return false;
    return true;
}