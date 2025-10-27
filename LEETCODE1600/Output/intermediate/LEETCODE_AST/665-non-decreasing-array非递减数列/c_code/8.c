bool checkPossibility(int* nums, int numsSize){
    int i=0,j=0;
    if(numsSize==1||numsSize==2) return true;
    while(i<numsSize-1){
        if(nums[i]>nums[i+1]){
            break;
        }
        i++;
    }
    if((i+1==numsSize)||(i+2==numsSize)) return true;
    if(nums[i]>nums[i+1]&&nums[i]<=nums[i+2]) nums[i+1]=nums[i];
    if(nums[i]>nums[i+1]&&nums[i]>nums[i+2]) nums[i]=nums[i+1];
    while(j<numsSize-1){
        if(nums[j]>nums[j+1]){
            break;
        }
        j++;
    }
    j++;
    if(j==numsSize) return true;
    else return false;

}