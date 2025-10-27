int findLengthOfLCIS(int* nums, int numsSize){
    if(numsSize==0||numsSize==1) return numsSize;
    int i,j,res=1;
    j=numsSize-1;
    while(j>0){
        nums[j]=nums[j]-nums[j-1];
        j--;
    }
    for(i=0,j=1;j<numsSize;){
        while(j<numsSize&&nums[j]>0)j++;
        res=res>j-i?res:j-i;
        while(j<numsSize&&nums[j]<=0)j++;
        i=j-1;
    }
    return res;
}