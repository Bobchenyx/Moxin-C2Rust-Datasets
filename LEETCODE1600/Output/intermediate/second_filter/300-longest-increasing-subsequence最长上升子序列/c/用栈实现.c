int lengthOfLIS(int* nums, int numsSize){
    if(numsSize<2)
        return numsSize;
    int top=0, i, j;
    int stack[numsSize];
    stack[top++] = nums[0];
    for(i=1; i<numsSize; i++){
        if(nums[i]>stack[top-1]){
            stack[top++] = nums[i]; 
        }else{
            for(j=0; j <top; j++){
                if(nums[i]<=stack[j]){
                    stack[j] = nums[i];
                    break;
                }
            }
        }
    }
    return top;
}