int removeDuplicates(int* nums, int numsSize){
    int i,j,k;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j]){
                for(k=j;k<numsSize-1;k++){
                    nums[k]=nums[k+1]; 
                }
                numsSize-=1;
                j=j-1;
            }
        }
    }
    return numsSize;
}